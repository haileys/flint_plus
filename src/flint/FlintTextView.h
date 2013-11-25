#import <AppKit/AppKit.h>
#import "FlintAutocompleteController.h"
#import "FlintAutocompleteControllerDelegate.h"

@interface FlintTextView : NSTextView <FlintAutocompleteControllerDelegate, NSPopoverDelegate>
{
    BOOL _paste;
    FlintAutocompleteController *_autocompleteController;
    BOOL _forcePaste;
    NSPopover *_popover;
}

+ (void)initialize;
@property(retain) NSPopover *popover; // @synthesize popover=_popover;
@property(nonatomic) BOOL forcePaste; // @synthesize forcePaste=_forcePaste;
@property(retain) FlintAutocompleteController *autocompleteController; // @synthesize autocompleteController=_autocompleteController;
@property(nonatomic) BOOL paste; // @synthesize paste=_paste;
- (void)drawViewBackgroundInRect:(struct CGRect)arg1;
- (BOOL)performDragOperation:(id)arg1;
- (BOOL)readSelectionFromPasteboard:(id)arg1 type:(id)arg2;
- (id)readablePasteboardTypes;
- (void)togglePaste:(id)arg1;
- (void)paste:(id)arg1;
- (BOOL)isPaste;
- (void)continueAutocompleteWithString:(id)arg1;
- (void)insertAutocompleteItem:(id)arg1;
- (struct _NSRange)rangeForUserCompletion;
- (void)insertTab:(id)arg1;
- (void)popoverDidClose:(id)arg1;
- (void)autocomplete;
- (BOOL)isCursorAtBeginning;
- (void)clearText;
- (void)refresh;
- (void)updateFontSize:(id)arg1;
- (void)reset;
- (void)insertNewline:(id)arg1;
- (id)menuForEvent:(id)arg1;
- (void)keyDown:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)dealloc;

@end
