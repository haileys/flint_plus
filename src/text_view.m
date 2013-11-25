#import <AppKit/AppKit.h>
#import "flint/FlintTextView.h"
#import "hackery.h"

static NSMutableDictionary*
fake_ivar_dict;

static NSMutableDictionary*
get_fake_ivar_dict(id object)
{
    id key = [NSNumber numberWithInt:(int)object];
    NSMutableDictionary* dict = [fake_ivar_dict objectForKey:key];
    if(dict == nil) {
        dict = [NSMutableDictionary dictionary];
        [fake_ivar_dict setObject:dict forKey:key];
    }
    return dict;
}

static void
destroy_fake_ivar_dict(id object)
{
    id key = [NSNumber numberWithInt:(int)object];
    [fake_ivar_dict removeObjectForKey:key];
}

static id
get_fake_ivar(id object, NSString* name)
{
    return [get_fake_ivar_dict(object) objectForKey:name];
}

static void
set_fake_ivar(id object, NSString* name, id value)
{
    [get_fake_ivar_dict(object) setObject:value forKey:name];
}

static NSMutableArray*
get_history(id object)
{
    NSMutableArray* history = get_fake_ivar(object, @"history");
    if(history == nil) {
        history = [NSMutableArray array];
        set_fake_ivar(object, @"history", history);
    }
    return history;
}

static int
get_position(id object)
{
    return [(NSNumber*)get_fake_ivar(object, @"position") intValue];
}

static void
set_position(id object, int position)
{
    set_fake_ivar(object, @"position", [NSNumber numberWithInt:position]);
}

static void
add_line_to_history(FlintTextView* text_view)
{
    set_position(text_view, 0);

    NSMutableAttributedString* copy = [[NSMutableAttributedString alloc] init];
    [copy setAttributedString:[text_view textStorage]];

    NSMutableArray* history = get_history(text_view);
    [history insertObject:copy atIndex:0];
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
- (void)original_dealloc;
- (void)original_keyDown:(NSEvent*)event;
@end

@implementation flint_plus_FlintTextView
- (void)original_dealloc
{
    destroy_fake_ivar_dict(self);
    [self original_dealloc];
}

#define KEY_ENTER 36
#define KEY_UP    126
#define KEY_DOWN  125

- (void)keyDown:(NSEvent*)event
{
    int key_code = [event keyCode];
    if(key_code == KEY_ENTER) {
        if(!([event modifierFlags] & (NSShiftKeyMask | NSControlKeyMask | NSAlternateKeyMask))) {
            add_line_to_history((FlintTextView*)self);
        }
    } else if(key_code == KEY_UP) {
        history_up((FlintTextView*)self);
        return;
    } else if(key_code == KEY_DOWN) {
        history_down((FlintTextView*)self);
        return;
    }

    [self original_keyDown: event];
}
@end

void
flint_plus_init_text_view()
{
    fake_ivar_dict = [NSMutableDictionary dictionary];
    [fake_ivar_dict retain];

    flint_plus_patch("FlintTextView", "keyDown:");
}
