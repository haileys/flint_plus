#import <AppKit/AppKit.h>

@interface FlintAboutController : NSWindowController
{
    NSTextField *_version;
}

@property __weak NSTextField *version; // @synthesize version=_version;
- (void)close:(id)arg1;
- (void)awakeFromNib;
- (id)init;

@end
