#import <AppKit/AppKit.h>
#import "flint/FlintTextView.h"
#import "hackery.h"
#import "fake_ivar.h"

static NSMutableArray*
get_history(id object)
{
    NSMutableArray* history = flint_plus_get_fake_ivar(object, @"history");
    if(history == nil) {
        history = [NSMutableArray array];
        flint_plus_set_fake_ivar(object, @"history", history);
    }
    return history;
}

static int
get_position(id object)
{
    return [(NSNumber*)flint_plus_get_fake_ivar(object, @"position") intValue];
}

static void
set_position(id object, int position)
{
    flint_plus_set_fake_ivar(object, @"position", [NSNumber numberWithInt:position]);
}

static bool
on_message_sent(FlintTextView* text_view)
{
    set_position(text_view, 0);

    NSMutableAttributedString* copy = [[NSMutableAttributedString alloc] init];
    [copy setAttributedString:[text_view textStorage]];

    NSMutableArray* history = get_history(text_view);
    [history insertObject:copy atIndex:0];

    return true;
}

static void
history_direction(FlintTextView* text_view, int direction)
{
    NSMutableArray* history = get_history(text_view);
    NSMutableAttributedString* str = nil;

    int position = get_position(text_view) + direction;

    if(position <= 0) {
        set_position(text_view, 0);
        str = [[NSMutableAttributedString alloc] initWithString: @""];
    } else if(position > [history count]) {
        set_position(text_view, [history count]);
        str = [[NSMutableAttributedString alloc] initWithString: @""];
    } else {
        set_position(text_view, position);
        str = [history objectAtIndex:position - 1];
    }

    [[text_view textStorage] setAttributedString:str];
    [text_view setSelectedRange:(NSRange){[str length], 0}];
}

static void
history_up(FlintTextView* text_view)
{
    history_direction(text_view, 1);
}

static void
history_down(FlintTextView* text_view)
{
    history_direction(text_view, -1);
}

@interface flint_plus_FlintTextView : NSObject
- (void)original_keyDown:(NSEvent*)event;
@end

@implementation flint_plus_FlintTextView

#define KEY_ENTER 36
#define KEY_UP    126
#define KEY_DOWN  125

- (void)keyDown:(NSEvent*)event
{
    FlintTextView* ftv = (FlintTextView*)self;

    int key_code = [event keyCode];

    if(key_code == KEY_ENTER) {
        if(!([event modifierFlags] & (NSShiftKeyMask | NSControlKeyMask | NSAlternateKeyMask))) {
            if(!on_message_sent(ftv)) {
                [ftv clearText];
                return;
            }
        }
    } else if(key_code == KEY_UP) {
        history_up(ftv);
        return;
    } else if(key_code == KEY_DOWN) {
        history_down(ftv);
        return;
    }

    [self original_keyDown: event];
}
@end

void
flint_plus_init_text_view()
{
    flint_plus_patch("FlintTextView", "keyDown:");
}
