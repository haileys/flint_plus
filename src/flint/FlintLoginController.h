#import <AppKit/AppKit.h>
#import <WebKit/WebKit.h>

@interface FlintLoginController : NSWindowController <NSWindowDelegate>
{
    NSButton *_authButton;
    NSWindow *_authWindow;
    NSTextField *_status;
    NSProgressIndicator *_progress;
    WebView *_webView;
}

@property __weak WebView *webView; // @synthesize webView=_webView;
@property __weak NSProgressIndicator *progress; // @synthesize progress=_progress;
@property __weak NSTextField *status; // @synthesize status=_status;
@property NSWindow *authWindow; // @synthesize authWindow=_authWindow;
@property __weak NSButton *authButton; // @synthesize authButton=_authButton;
- (void)authenticateWithCode:(id)arg1;
- (void)webView:(id)arg1 decidePolicyForNavigationAction:(id)arg2 request:(id)arg3 frame:(id)arg4 decisionListener:(id)arg5;
- (void)authenticate:(id)arg1;
- (void)cancel:(id)arg1;
- (void)awakeFromNib;
- (id)init;

@end
