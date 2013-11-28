#import <AppKit/AppKit.h>

@interface FlintPreferencesController : NSWindowController <NSToolbarDelegate, NSTableViewDelegate, NSTableViewDataSource, NSWindowDelegate>
{
    NSView *_accountsView;
    NSView *_advancedView;
    NSTextField *_keywords;
    NSTableView *_accountsTable;
    NSToolbar *_toolbar;
    NSTextField *_accountStatus;
    NSPopUpButton *_keywordNotifications;
    NSView *_currentView;
    NSProgressIndicator *_progress;
    NSButton *_autoPlayGifs;
    NSView *_generalView;
    NSPopUpButton *_messagesNotifications;
    /*IGIsolatedCookieWebView*/void *_webView;
    NSPopUpButton *_sounds;
    NSButton *_showMenuBarIcon;
    NSView *_notificationsView;
    NSString *_currentToolbarIdentifier;
    NSView *_view;
    NSPopUpButton *_menuBarOptions;
    NSButton *_downloadsPath;
    NSWindow *_accountWindow;
    NSTextField *_inputFontSize;
    NSButton *_showInline;
}

@property __weak NSButton *showInline; // @synthesize showInline=_showInline;
@property __weak NSTextField *inputFontSize; // @synthesize inputFontSize=_inputFontSize;
@property NSWindow *accountWindow; // @synthesize accountWindow=_accountWindow;
@property __weak NSButton *downloadsPath; // @synthesize downloadsPath=_downloadsPath;
@property __weak NSPopUpButton *menuBarOptions; // @synthesize menuBarOptions=_menuBarOptions;
@property __weak NSView *view; // @synthesize view=_view;
@property(retain) NSString *currentToolbarIdentifier; // @synthesize currentToolbarIdentifier=_currentToolbarIdentifier;
@property __weak NSView *notificationsView; // @synthesize notificationsView=_notificationsView;
@property __weak NSButton *showMenuBarIcon; // @synthesize showMenuBarIcon=_showMenuBarIcon;
@property __weak NSPopUpButton *sounds; // @synthesize sounds=_sounds;
//@property(retain) IGIsolatedCookieWebView *webView; // @synthesize webView=_webView;
@property __weak NSPopUpButton *messagesNotifications; // @synthesize messagesNotifications=_messagesNotifications;
@property __weak NSView *generalView; // @synthesize generalView=_generalView;
@property __weak NSButton *autoPlayGifs; // @synthesize autoPlayGifs=_autoPlayGifs;
@property __weak NSProgressIndicator *progress; // @synthesize progress=_progress;
@property(nonatomic) __weak NSView *currentView; // @synthesize currentView=_currentView;
@property __weak NSPopUpButton *keywordNotifications; // @synthesize keywordNotifications=_keywordNotifications;
@property __weak NSTextField *accountStatus; // @synthesize accountStatus=_accountStatus;
@property __weak NSToolbar *toolbar; // @synthesize toolbar=_toolbar;
@property __weak NSTableView *accountsTable; // @synthesize accountsTable=_accountsTable;
@property __weak NSTextField *keywords; // @synthesize keywords=_keywords;
@property __weak NSView *advancedView; // @synthesize advancedView=_advancedView;
@property __weak NSView *accountsView; // @synthesize accountsView=_accountsView;
- (void)toggleHideInsteadOfClose:(id)arg1;
- (void)changeDownloadsPath:(id)arg1;
- (void)updateInputFontSize:(id)arg1;
- (void)webView:(id)arg1 decidePolicyForNavigationAction:(id)arg2 request:(id)arg3 frame:(id)arg4 decisionListener:(id)arg5;
- (void)cancelAuthentication:(id)arg1;
- (void)removeAccount:(id)arg1;
- (void)addAccount:(id)arg1;
- (BOOL)tableView:(id)arg1 acceptDrop:(id)arg2 row:(long long)arg3 dropOperation:(unsigned long long)arg4;
- (unsigned long long)tableView:(id)arg1 validateDrop:(id)arg2 proposedRow:(long long)arg3 proposedDropOperation:(unsigned long long)arg4;
- (BOOL)tableView:(id)arg1 writeRowsWithIndexes:(id)arg2 toPasteboard:(id)arg3;
- (id)tableView:(id)arg1 objectValueForTableColumn:(id)arg2 row:(long long)arg3;
- (long long)numberOfRowsInTableView:(id)arg1;
- (void)menuNeedsUpdate:(id)arg1;
- (void)updateKeywords:(id)arg1;
- (void)updateNotificationMenu:(id)arg1;
- (void)updateTabPosition:(id)arg1;
- (void)toggleShowEnterLeaveMessages:(id)arg1;
- (void)toggleAutoPlayGifs:(id)arg1;
- (void)updateInlineImagesMode:(id)arg1;
- (void)refreshMessages:(id)arg1;
- (void)toggleMenuBarCounts:(id)arg1;
- (void)toggleMenuBarIcon:(id)arg1;
- (void)playSound:(id)arg1;
- (void)toolbarItemSelected:(id)arg1;
- (void)close:(id)arg1;
- (void)windowWillClose:(id)arg1;
- (void)awakeFromNib;
- (id)init;

@end
