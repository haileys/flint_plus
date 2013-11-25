#import <AppKit/AppKit.h>

@interface FlintDownloadsController : NSWindowController <NSTableViewDataSource, NSTableViewDelegate/*, QLPreviewPanelDataSource, QLPreviewPanelDelegate*/>
{
    NSMutableArray *_downloads;
    NSTableView *_tableView;
}

@property __weak NSTableView *tableView; // @synthesize tableView=_tableView;
@property(retain) NSMutableArray *downloads; // @synthesize downloads=_downloads;
- (void)endPreviewPanelControl:(id)arg1;
- (void)beginPreviewPanelControl:(id)arg1;
- (BOOL)acceptsPreviewPanelControl:(id)arg1;
- (id)previewPanel:(id)arg1 transitionImageForPreviewItem:(id)arg2 contentRect:(struct CGRect *)arg3;
- (struct CGRect)previewPanel:(id)arg1 sourceFrameOnScreenForPreviewItem:(id)arg2;
- (id)previewPanel:(id)arg1 previewItemAtIndex:(long long)arg2;
- (long long)numberOfPreviewItemsInPreviewPanel:(id)arg1;
- (id)tableView:(id)arg1 viewForTableColumn:(id)arg2 row:(long long)arg3;
- (long long)numberOfRowsInTableView:(id)arg1;
- (void)quickLookUploadAtIndex:(long long)arg1;
- (void)openDownloadInFinder:(id)arg1;
- (void)openDownload:(id)arg1;
- (void)downloadProgressed:(id)arg1;
- (void)downloadUpload:(id)arg1;
- (void)close:(id)arg1;
- (void)awakeFromNib;
- (id)init;

@end
