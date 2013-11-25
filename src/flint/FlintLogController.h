#import <AppKit/AppKit.h>

@interface FlintLogController : NSWindowController <NSTableViewDelegate, NSTableViewDataSource>
{
    NSTableView *_tableView;
}

+ (void)initialize;
@property __weak NSTableView *tableView; // @synthesize tableView=_tableView;
- (id)tableView:(id)arg1 objectValueForTableColumn:(id)arg2 row:(long long)arg3;
- (long long)numberOfRowsInTableView:(id)arg1;
- (void)refresh:(id)arg1;
- (void)copyLogs:(id)arg1;
- (void)close:(id)arg1;
- (void)windowDidLoad;
- (id)init;

@end
