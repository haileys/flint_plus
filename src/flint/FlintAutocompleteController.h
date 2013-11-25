#import <AppKit/AppKit.h>
#import "FlintAutocompleteControllerDelegate.h"

@interface FlintAutocompleteController : NSViewController <NSTableViewDataSource, NSTableViewDelegate>
{
    NSTableView *_tableView;
    NSArray *_completions;
    id <FlintAutocompleteControllerDelegate> _delegate;
}

@property id <FlintAutocompleteControllerDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) NSArray *completions; // @synthesize completions=_completions;
@property __weak NSTableView *tableView; // @synthesize tableView=_tableView;
- (void)insertSelectedRow:(id)arg1;
- (id)tableView:(id)arg1 viewForTableColumn:(id)arg2 row:(long long)arg3;
- (long long)numberOfRowsInTableView:(id)arg1;
- (void)filterListWithString:(id)arg1;
- (void)awakeFromNib;
- (id)init;
- (void)dealloc;

@end
