#import <AppKit/AppKit.h>
#import <WebKit/WebKit.h>

typedef id CDUnknownBlockType;
typedef NSObject PLKItem;
typedef NSObject AFImageRequestOperation;

@class FlintAccount;
@class FlintAppDelegate;
@class FlintAutocompleteItem;
@class FlintBottomViewController;
@class FlintCampfireClient;
@class FlintCampfireRoomConnection;
@class FlintCampfireUpload;
@class FlintDownloadsController;
@class FlintEmbed;
@class FlintErrorView;
@class FlintFindController;
@class FlintLogController;
@class FlintLoginController;
@class FlintMessagesCollection;
@class FlintPreferencesController;
@class FlintRoomController;
@class FlintRoomSettings;
@class FlintSplitView;
@class FlintTableView;
@class FlintTweet;
@class FlintUnreadCounts;
@class FlintUsersController;
@class FlintWindowController;

@protocol FlintAutocompleteControllerDelegate;
@protocol FlintEmbedViewDelegate;
@protocol FlintTableViewDelegate;

extern FlintAppDelegate*
flint;

@interface FlintViewController : NSViewController <NSUserInterfaceValidations, NSSplitViewDelegate>
{
    NSProgressIndicator *_spinner;
    NSTabViewItem *_tabViewItem;
    NSPopover *_errorPopover;
    long long _objectCount;
    NSString *_error;
    FlintErrorView *_errorView;
    FlintWindowController *_windowController;
    NSButton *_errorButton;
}

@property(retain) NSButton *errorButton; // @synthesize errorButton=_errorButton;
@property FlintWindowController *windowController; // @synthesize windowController=_windowController;
@property(retain) FlintErrorView *errorView; // @synthesize errorView=_errorView;
@property(retain) NSString *error; // @synthesize error=_error;
@property(nonatomic) long long objectCount; // @synthesize objectCount=_objectCount;
@property(retain) NSPopover *errorPopover; // @synthesize errorPopover=_errorPopover;
@property __weak NSTabViewItem *tabViewItem; // @synthesize tabViewItem=_tabViewItem;
@property(retain) NSProgressIndicator *spinner; // @synthesize spinner=_spinner;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (BOOL)validateMenuItem:(id)arg1;
- (void)displayError:(id)arg1;
- (void)hideError;
- (void)showError;
- (void)removeSpinner;
- (void)showSpinner;
- (void)removeView:(id)arg1 animated:(BOOL)arg2;
- (void)insertViewAtBottom:(id)arg1 animated:(BOOL)arg2;
- (void)insertViewAtBottom:(id)arg1;
- (void)insertViewAtTop:(id)arg1 animated:(BOOL)arg2;
- (void)insertViewAtTop:(id)arg1;
- (id)containerView;
- (id)windowTitle;
- (void)viewWillDisappear;
- (void)viewWillClose;
- (void)viewDidBecomeActive;
- (void)windowWillClose;
- (void)setTitle:(id)arg1;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (id)init;
- (void)dealloc;

@end

@protocol FlintTableViewDelegate <NSObject>
- (void)tableView:(NSTableView *)arg1 didClickRow:(long long)arg2 inView:(NSView *)arg3 event:(NSEvent *)arg4;

@optional
- (NSMenu *)tableView:(NSTableView *)arg1 menuForRow:(long long)arg2;
@end

@interface FlintLobbyController : FlintViewController <NSTableViewDataSource, NSTableViewDelegate, FlintTableViewDelegate>
{
    NSMutableArray *_data;
    NSMutableDictionary *_accountStatus;
    FlintTableView *_tableView;
    NSDictionary *_currentFind;
    BOOL _awake;
}

@property BOOL awake; // @synthesize awake=_awake;
@property(retain) NSDictionary *currentFind; // @synthesize currentFind=_currentFind;
@property __weak FlintTableView *tableView; // @synthesize tableView=_tableView;
@property(retain) NSMutableDictionary *accountStatus; // @synthesize accountStatus=_accountStatus;
@property(retain) NSMutableArray *data; // @synthesize data=_data;
- (void)accountsUpdated:(id)arg1;
- (void)viewTranscript:(id)arg1;
- (void)keyDown:(id)arg1;
- (void)tableView:(id)arg1 didClickRow:(long long)arg2 inView:(id)arg3 event:(id)arg4;
- (double)tableView:(id)arg1 heightOfRow:(long long)arg2;
- (BOOL)tableView:(id)arg1 shouldSelectRow:(long long)arg2;
- (id)tableView:(id)arg1 viewForTableColumn:(id)arg2 row:(long long)arg3;
- (id)tableView:(id)arg1 rowViewForRow:(long long)arg2;
- (BOOL)tableView:(id)arg1 isGroupRow:(long long)arg2;
- (long long)numberOfRowsInTableView:(id)arg1;
- (void)roomControllerUpdated:(id)arg1;
- (id)objectForRow:(long long)arg1;
- (void)loadRooms;
- (void)viewWillDisappear;
- (void)viewDidBecomeActive;
- (void)flattenAccounts;
- (id)containerView;
- (void)awakeFromNib;
- (id)init;
- (void)dealloc;

@end

@interface FlintAboutController : NSWindowController
{
    NSTextField *_version;
}

@property __weak NSTextField *version; // @synthesize version=_version;
- (void)close:(id)arg1;
- (void)awakeFromNib;
- (id)init;

@end

@interface FlintAppDelegate : NSObject <NSApplicationDelegate/*, GrowlApplicationBridgeDelegate, BITCrashReportManagerDelegate*/, NSMenuDelegate>
{
    FlintAboutController *_aboutController;
    FlintLoginController *_loginController;
    FlintLogController *_logController;
    FlintPreferencesController *_preferencesController;
    FlintDownloadsController *_downloadsController;
    NSMutableArray *_windowControllers;
    NSStatusItem *_statusItem;
    BOOL _ignoreNextActivation;
    BOOL _sleeping;
    NSMenuItem *_checkForUpdatesMenuItem;
}

@property __weak NSMenuItem *checkForUpdatesMenuItem; // @synthesize checkForUpdatesMenuItem=_checkForUpdatesMenuItem;
@property BOOL sleeping; // @synthesize sleeping=_sleeping;
@property BOOL ignoreNextActivation; // @synthesize ignoreNextActivation=_ignoreNextActivation;
@property(retain) NSStatusItem *statusItem; // @synthesize statusItem=_statusItem;
@property(retain) NSMutableArray *windowControllers; // @synthesize windowControllers=_windowControllers;
@property(retain) FlintDownloadsController *downloadsController; // @synthesize downloadsController=_downloadsController;
@property(retain) FlintPreferencesController *preferencesController; // @synthesize preferencesController=_preferencesController;
@property(retain) FlintLogController *logController; // @synthesize logController=_logController;
@property(retain) FlintLoginController *loginController; // @synthesize loginController=_loginController;
@property(retain) FlintAboutController *aboutController; // @synthesize aboutController=_aboutController;
- (void)checkForTrialExpiration;
- (void)checkForBetaExpiration;
- (void)showMainApplicationWindow;
- (BOOL)hasNetworkClientEntitlement;
- (void)growlNotificationWasClicked:(id)arg1;
- (id)registrationDictionaryForGrowl;
- (void)viewAcknowledgments:(id)arg1;
- (void)viewReleaseNotes:(id)arg1;
- (void)submitFeedback:(id)arg1;
- (void)viewHelp:(id)arg1;
- (void)startMonitoringNetworkStatus;
- (void)handleURLEvent:(id)arg1 withReplyEvent:(id)arg2;
- (void)toggleApp:(id)arg1;
- (void)removeStatusItem;
- (void)addStatusItem;
- (void)menuNeedsUpdate:(id)arg1;
- (BOOL)isRoomOpen:(id)arg1;
- (void)flintWindowClosed:(id)arg1;
- (void)addWindowController:(id)arg1;
- (id)windowControllersForActiveSpace;
- (id)mostRecentlyUsedWindowControllers;
- (BOOL)needsToActivateMostRecentlyActiveRoom;
- (void)activateMostRecentlyActiveRoom;
- (void)activateMostRecentlyUsedWindow;
- (void)activateRoomWithRoomId:(unsigned long long)arg1;
- (void)activateRoom:(id)arg1;
- (void)bringWindowsToFront:(id)arg1;
- (void)newSearch:(id)arg1;
- (void)newWindow:(id)arg1;
- (void)saveWindows;
- (void)restoreWindows;
- (void)downloadUpload:(id)arg1;
- (void)showLog:(id)arg1;
- (void)showDownloads:(id)arg1;
- (void)showPreferences:(id)arg1;
- (void)showAbout:(id)arg1;
- (void)loginComplete:(id)arg1;
- (void)showLoginWindow;
- (void)computerDidWake:(id)arg1;
- (void)computerWillSleep:(id)arg1;
- (void)applicationDidResignActive:(id)arg1;
- (void)applicationWillBecomeActive:(id)arg1;
- (BOOL)applicationShouldHandleReopen:(id)arg1 hasVisibleWindows:(BOOL)arg2;
- (void)applicationWillTerminate:(id)arg1;
- (void)applicationDidFinishLaunching:(id)arg1;
- (void)applicationWillFinishLaunching:(id)arg1;

@end

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

@protocol FlintAutocompleteControllerDelegate <NSObject>
- (void)insertAutocompleteItem:(FlintAutocompleteItem *)arg1;
- (void)continueAutocompleteWithString:(NSString *)arg1;
@end

@interface FlintAutocompleteItem : NSObject
{
    NSString *_completion;
    int _type;
    NSImage *_image;
    NSString *_emoji;
    NSString *_name;
}

+ (id)autocompleteItemWithName:(id)arg1 image:(id)arg2;
@property(retain) NSString *name; // @synthesize name=_name;
@property(retain) NSString *emoji; // @synthesize emoji=_emoji;
@property(retain) NSImage *image; // @synthesize image=_image;
@property int type; // @synthesize type=_type;
@property(retain) NSString *completion; // @synthesize completion=_completion;
- (id)description;
- (id)init;

@end

@interface FlintCampfireClient : /*AFHTTPClient*/ NSObject
{
    NSString *_token;
    NSTimeZone *_timezone;
    NSString *_domain;
}

@property(readonly) NSString *domain; // @synthesize domain=_domain;
@property(retain) NSTimeZone *timezone; // @synthesize timezone=_timezone;
@property(readonly) NSString *token; // @synthesize token=_token;
- (id)errorForOperation:(id)arg1 error:(id)arg2;
- (void)logErrorForOperation:(id)arg1 error:(id)arg2 message:(id)arg3;
- (void)cancelRequestForPaths:(id)arg1 method:(id)arg2 exact:(BOOL)arg3;
- (void)cancelRequestForPaths:(id)arg1 exact:(BOOL)arg2;
- (void)cancelRequestForPath:(id)arg1 exact:(BOOL)arg2;
- (void)cancelRequestForPath:(id)arg1;
- (void)transcriptforRoom:(id)arg1 date:(id)arg2 completion:(CDUnknownBlockType)arg3;
- (id)transcriptURLForRoom:(id)arg1 date:(id)arg2;
- (id)transcriptPathForRoom:(id)arg1 date:(id)arg2;
- (void)searchForTerm:(id)arg1 fromIndex:(long long)arg2 completion:(CDUnknownBlockType)arg3;
- (void)unstarMessage:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)starMessage:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)postMessage:(id)arg1 room:(id)arg2 completion:(CDUnknownBlockType)arg3;
- (void)updateTopic:(id)arg1 room:(id)arg2 completion:(CDUnknownBlockType)arg3;
- (void)uploadFile:(id)arg1 room:(id)arg2 progress:(CDUnknownBlockType)arg3 completion:(CDUnknownBlockType)arg4;
- (void)uploadForMessage:(id)arg1 room:(id)arg2 completion:(CDUnknownBlockType)arg3;
- (void)uploadsForRoom:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)cancelRequestsForRoom:(id)arg1;
- (void)pingRoom:(id)arg1;
- (void)leaveRoom:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)leaveRoom:(id)arg1;
- (void)infoForRoom:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)recentMessagesForRoom:(id)arg1 sinceMessage:(id)arg2 completion:(CDUnknownBlockType)arg3;
- (void)unlockRoom:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)lockRoom:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)joinRoom:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)userWithUserID:(unsigned long long)arg1 completion:(CDUnknownBlockType)arg2;
- (void)roomsForAccount:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)accountWithCompletion:(CDUnknownBlockType)arg1;
- (id)initWithDomain:(id)arg1 token:(id)arg2;

@end

#undef CDUnknownBlockType

@interface FlintCampfireMessage : NSObject
{
    NSMutableArray *_emojiRanges;
    NSString *_originalBody;
    unsigned long long _uid;
    FlintEmbed *_embed;
    NSString *_body;
    NSString *_type;
    unsigned long long _roomId;
    NSDate *_createdAt;
    BOOL _emojiReplaced;
    unsigned long long _userId;
    BOOL _starred;
    NSMutableArray *_urlRanges;
    BOOL _mention;
    BOOL _pending;
    FlintTweet *_tweet;
    FlintCampfireUpload *_upload;
}

+ (id)messageWithBody:(id)arg1 type:(id)arg2 forUser:(id)arg3;
+ (id)messageWithBody:(id)arg1 forUser:(id)arg2;
+ (id)messageWithDictionary:(id)arg1;
+ (void)initialize;
@property(retain, nonatomic) FlintCampfireUpload *upload; // @synthesize upload=_upload;
@property(retain) FlintTweet *tweet; // @synthesize tweet=_tweet;
@property BOOL pending; // @synthesize pending=_pending;
@property BOOL mention; // @synthesize mention=_mention;
@property(retain) NSMutableArray *urlRanges; // @synthesize urlRanges=_urlRanges;
@property BOOL starred; // @synthesize starred=_starred;
@property(readonly) unsigned long long userId; // @synthesize userId=_userId;
@property BOOL emojiReplaced; // @synthesize emojiReplaced=_emojiReplaced;
@property(readonly) NSDate *createdAt; // @synthesize createdAt=_createdAt;
@property(readonly) unsigned long long roomId; // @synthesize roomId=_roomId;
@property(readonly) NSString *type; // @synthesize type=_type;
@property(retain) NSString *body; // @synthesize body=_body;
@property(retain, nonatomic) FlintEmbed *embed; // @synthesize embed=_embed;
@property(readonly) unsigned long long uid; // @synthesize uid=_uid;
@property(readonly) NSString *originalBody; // @synthesize originalBody=_originalBody;
@property(retain) NSMutableArray *emojiRanges; // @synthesize emojiRanges=_emojiRanges;
- (void)notifyMessageWasUpdated:(BOOL)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)checkForEmbed;
- (BOOL)hasVisibleEmbed;
- (id)dictionaryRepresentation;
- (id)JSONData;
- (BOOL)containsMentionForKeywords:(id)arg1;
- (void)checkForMentions;
- (void)checkForLinks;
- (void)replaceEmoji;
- (void)processBody;
- (id)transcriptBody;
- (id)notificationText;
- (BOOL)isFollowUpOfMessage:(id)arg1;
- (void)playSound;
- (BOOL)shouldRenderEmoji;
- (BOOL)isConferenceFinished;
- (BOOL)isTweet;
- (BOOL)isSound;
- (BOOL)isPaste;
- (BOOL)isUnlock;
- (BOOL)isLock;
- (BOOL)disallowGuests;
- (BOOL)allowGuests;
- (BOOL)isUpload;
- (BOOL)isTopicChange;
- (BOOL)isExit;
- (BOOL)isEntrance;
- (BOOL)isSystemUpdate;
- (BOOL)isStatusUpdate;
- (BOOL)isRemark;
- (BOOL)isUserUpdate;
- (id)description;
- (BOOL)isEqualToMessage:(id)arg1;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (id)initWithDictionary:(id)arg1;
- (id)init;
- (void)dealloc;

@end

@interface FlintCampfireRoom : NSObject <NSCoding>
{
    BOOL _guests;
    FlintRoomSettings *_settings;
    NSMutableSet *_users;
    NSString *_name;
    NSMutableArray *_uploads;
    unsigned long long _uid;
    NSString *_topic;
    BOOL _locked;
}

@property BOOL locked; // @synthesize locked=_locked;
@property(copy, nonatomic) NSString *topic; // @synthesize topic=_topic;
@property unsigned long long uid; // @synthesize uid=_uid;
@property(retain) NSMutableArray *uploads; // @synthesize uploads=_uploads;
@property(copy) NSString *name; // @synthesize name=_name;
@property(retain) NSMutableSet *users; // @synthesize users=_users;
@property(retain) FlintRoomSettings *settings; // @synthesize settings=_settings;
@property BOOL guests; // @synthesize guests=_guests;
- (void)removeUserFromRoom:(id)arg1;
- (void)addUserToRoom:(id)arg1;
- (void)reset;
- (id)title;
- (void)updateWithRoom:(id)arg1;
- (BOOL)isEqualToRoom:(id)arg1;
- (id)description;
- (void)updateWithDictionary:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithDictionary:(id)arg1;
- (id)init;

@end

@protocol FlintCampfireRoomConnectionDelegate <NSObject>
- (void)connectionErrorOccurred:(NSString *)arg1;
- (void)connectionDidConnect;
- (void)connectionDidReceiveMessages:(NSArray *)arg1 streamed:(BOOL)arg2;
@end

@interface FlintCampfireUpload : NSObject
{
    NSString *_contentType;
    FlintCampfireClient *_client;
    BOOL _downloaded;
    NSString *_name;
    unsigned long long _messageId;
    unsigned long long _uploadId;
    NSURL *_url;
    unsigned long long _roomId;
    unsigned long long _userId;
    float _downloadPercentage;
    NSString *_downloadPath;
}

@property(copy) NSString *downloadPath; // @synthesize downloadPath=_downloadPath;
@property(nonatomic) float downloadPercentage; // @synthesize downloadPercentage=_downloadPercentage;
@property unsigned long long userId; // @synthesize userId=_userId;
@property unsigned long long roomId; // @synthesize roomId=_roomId;
@property(retain) NSURL *url; // @synthesize url=_url;
@property unsigned long long uploadId; // @synthesize uploadId=_uploadId;
@property unsigned long long messageId; // @synthesize messageId=_messageId;
@property(retain) NSString *name; // @synthesize name=_name;
@property BOOL downloaded; // @synthesize downloaded=_downloaded;
@property __weak FlintCampfireClient *client; // @synthesize client=_client;
@property(copy) NSString *contentType; // @synthesize contentType=_contentType;
- (id)previewItemTitle;
- (id)previewItemURL;
- (BOOL)fileExists;
- (id)description;
- (id)initWithDictionary:(id)arg1;

@end

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

@interface FlintEmbed : NSObject
{
    FlintCampfireClient *_client;
    NSString *_source;
    BOOL _animate;
    NSURL *_url;
    NSString *_type;
    PLKItem *_item;
    AFImageRequestOperation *_imageRequestOperation;
    BOOL _animated;
    BOOL _error;
    NSImage *_image;
    BOOL _hidden;
    NSImage *_scaledImage;
    BOOL _direct;
}

+ (void)checkForEmbedWithSource:(id)arg1 URL:(id)arg2 completion:(CDUnknownBlockType)arg3;
+ (void)embedForLink:(id)arg1 completion:(CDUnknownBlockType)arg2;
+ (BOOL)isEmbeddableLink:(id)arg1;
@property(nonatomic) BOOL direct; // @synthesize direct=_direct;
@property(retain) NSImage *scaledImage; // @synthesize scaledImage=_scaledImage;
@property(nonatomic) BOOL hidden; // @synthesize hidden=_hidden;
@property(retain, nonatomic) NSImage *image; // @synthesize image=_image;
@property BOOL error; // @synthesize error=_error;
@property(getter=isAnimated) BOOL animated; // @synthesize animated=_animated;
@property(retain) AFImageRequestOperation *imageRequestOperation; // @synthesize imageRequestOperation=_imageRequestOperation;
@property(retain) PLKItem *item; // @synthesize item=_item;
@property(copy, nonatomic) NSString *type; // @synthesize type=_type;
@property(retain) NSURL *url; // @synthesize url=_url;
@property(nonatomic) BOOL animate; // @synthesize animate=_animate;
@property(copy, nonatomic) NSString *source; // @synthesize source=_source;
@property(retain, nonatomic) FlintCampfireClient *client; // @synthesize client=_client;
- (void)writeToFile:(id)arg1;
- (id)fileType;
- (id)fileName;
- (double)heightForWidth:(double)arg1;
- (void)checkForAnimatedGif;
- (id)request;
- (void)download;
- (BOOL)loaded;
- (BOOL)hasPlayableVideo;
- (BOOL)isImage;
- (BOOL)isVideo;
- (id)description;
- (id)initWithURL:(id)arg1 client:(id)arg2;
- (id)initWithURL:(id)arg1;
- (id)init;

@end

#undef CDUnknownBlockType
#undef PLKItem
#undef AFImageRequestOperation

@interface FlintEmbedView : NSImageView
{
    BOOL _animated;
    BOOL _receivedMouseDown;
    BOOL _video;
    NSTrackingArea *_trackingArea;
    FlintEmbed *_embed;
    BOOL _dragging;
    id <FlintEmbedViewDelegate> _delegate;
}

@property id <FlintEmbedViewDelegate> delegate; // @synthesize delegate=_delegate;
@property BOOL dragging; // @synthesize dragging=_dragging;
@property(retain) FlintEmbed *embed; // @synthesize embed=_embed;
@property(retain) NSTrackingArea *trackingArea; // @synthesize trackingArea=_trackingArea;
@property BOOL video; // @synthesize video=_video;
@property BOOL receivedMouseDown; // @synthesize receivedMouseDown=_receivedMouseDown;
@property BOOL animated; // @synthesize animated=_animated;
- (void)saveImage:(id)arg1;
- (void)toggleAnimation:(id)arg1;
- (void)openInBrowser:(id)arg1;
- (void)copyEmbedLink:(id)arg1;
- (id)namesOfPromisedFilesDroppedAtDestination:(id)arg1;
- (void)mouseUp:(id)arg1;
- (void)mouseDragged:(id)arg1;
- (void)mouseDown:(id)arg1;
- (id)menuForEvent:(id)arg1;
- (void)updateTrackingAreas;
- (void)ensureTrackingArea;
- (void)mouseExited:(id)arg1;
- (void)mouseEntered:(id)arg1;
- (void)drawRect:(struct CGRect)arg1;
- (void)awakeFromNib;

@end

@protocol FlintEmbedViewDelegate <NSObject>

@optional
- (FlintCampfireMessage *)messageForEmbedView:(FlintEmbedView *)arg1;
- (void)didClickEmbedView:(FlintEmbedView *)arg1;
@end

@interface FlintErrorView : NSView
{
    NSTextField *_textField;
}

+ (id)stringAttributes;
@property(retain) NSTextField *textField; // @synthesize textField=_textField;
- (void)drawRect:(struct CGRect)arg1;
- (void)setError:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

@interface FlintErrorViewController : NSViewController
{
    NSTextField *_errorField;
    NSString *_error;
}

@property(copy, nonatomic) NSString *error; // @synthesize error=_error;
@property __weak NSTextField *errorField; // @synthesize errorField=_errorField;
- (void)updateErrorField;
- (void)awakeFromNib;
- (id)init;

@end

@protocol FlintFindControllerDelegate <NSObject>
- (void)findDidComplete;
- (void)nextFindMatch;
- (void)previousFindMatch;
- (void)findText:(NSString *)arg1;
@end

@protocol FlintInputDelegate <NSObject>
- (void)postMessage:(NSString *)arg1 paste:(BOOL)arg2;
@end

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

@interface FlintMessagesViewController : NSViewController <NSTableViewDataSource, NSTableViewDelegate, FlintTableViewDelegate, FlintEmbedViewDelegate, FlintFindControllerDelegate>
{
    FlintMessagesCollection *_messagesCollection;
    NSMapTable *_viewModels;
    struct CGRect _lastViewFrame;
    NSArray *_findMatches;
    NSTableView *_messagesView;
    NSString *_highlight;
    FlintFindController *_findController;
    BOOL _awake;
    BOOL _startAtBottom;
    BOOL _loadingEarlierMessages;
    unsigned long long _findIndex;
    BOOL _pullToRefresh;
    FlintCampfireRoom *_room;
    FlintAccount *_account;
    BOOL _wasAtBottom;
    FlintCampfireMessage *_loadEarlierMessage;
    BOOL _hasRefreshed;
    FlintRoomController *_roomController;
}

@property(nonatomic) FlintRoomController *roomController; // @synthesize roomController=_roomController;
@property BOOL hasRefreshed; // @synthesize hasRefreshed=_hasRefreshed;
@property(retain) FlintCampfireMessage *loadEarlierMessage; // @synthesize loadEarlierMessage=_loadEarlierMessage;
@property BOOL wasAtBottom; // @synthesize wasAtBottom=_wasAtBottom;
@property(retain) FlintAccount *account; // @synthesize account=_account;
@property(retain) FlintCampfireRoom *room; // @synthesize room=_room;
@property BOOL pullToRefresh; // @synthesize pullToRefresh=_pullToRefresh;
@property unsigned long long findIndex; // @synthesize findIndex=_findIndex;
@property BOOL loadingEarlierMessages; // @synthesize loadingEarlierMessages=_loadingEarlierMessages;
@property BOOL startAtBottom; // @synthesize startAtBottom=_startAtBottom;
@property BOOL awake; // @synthesize awake=_awake;
@property(retain) FlintFindController *findController; // @synthesize findController=_findController;
@property(retain, nonatomic) NSString *highlight; // @synthesize highlight=_highlight;
@property __weak NSTableView *messagesView; // @synthesize messagesView=_messagesView;
@property(retain) NSArray *findMatches; // @synthesize findMatches=_findMatches;
@property struct CGRect lastViewFrame; // @synthesize lastViewFrame=_lastViewFrame;
@property(retain) NSMapTable *viewModels; // @synthesize viewModels=_viewModels;
@property(retain, nonatomic) FlintMessagesCollection *messagesCollection; // @synthesize messagesCollection=_messagesCollection;
- (id)menuForMessage:(id)arg1 link:(id)arg2 selection:(id)arg3;
- (void)updateFindHighlightingForMessages:(id)arg1 text:(id)arg2;
- (void)nextFindMatch;
- (void)previousFindMatch;
- (void)findDidComplete;
- (void)cancel:(id)arg1;
- (void)findText:(id)arg1;
- (void)findPrevious:(id)arg1;
- (void)findNext:(id)arg1;
- (void)find:(id)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (void)scrollRowToVisible:(long long)arg1 animate:(BOOL)arg2;
- (void)scrollToBottomAnimated:(BOOL)arg1;
- (void)scrollToTopAnimated:(BOOL)arg1;
- (void)pageUp:(id)arg1;
- (void)pageDown:(id)arg1;
- (void)jumpToMessage:(id)arg1 animated:(BOOL)arg2;
- (void)jumpToMessage:(id)arg1;
- (void)jumpToBottom:(id)arg1;
- (void)jumpToTop:(id)arg1;
- (BOOL)isMessagesAtBottom;
- (void)didLoadEarlierMessages;
- (void)ptrScrollViewDidTriggerRefresh:(id)arg1;
- (void)openUpload:(id)arg1;
- (void)openPaste:(id)arg1;
- (void)openEmbed:(id)arg1;
- (void)openLinkInBrowser:(id)arg1 background:(BOOL)arg2;
- (void)openLinkInBrowser:(id)arg1;
- (void)openLink:(id)arg1 forMessage:(id)arg2;
- (void)viewInBrowser:(id)arg1;
- (void)copyLink:(id)arg1;
- (void)copyText:(id)arg1;
- (void)playSound:(id)arg1;
- (void)toggleImageAnimation:(id)arg1;
- (void)toggleInlineImageForMessage:(id)arg1;
- (void)toggleInlineImage:(id)arg1;
- (void)toggleStar:(id)arg1;
- (void)copy:(id)arg1;
- (id)textView:(id)arg1 menu:(id)arg2 forEvent:(id)arg3 atIndex:(unsigned long long)arg4;
- (BOOL)textView:(id)arg1 clickedOnLink:(id)arg2;
- (double)topOffsetOfTableView;
- (double)bottomOffsetOfTableView;
- (long long)bottomMarginForRow:(long long)arg1;
- (long long)topMarginForRow:(long long)arg1;
- (id)messagesForIndexes:(id)arg1;
- (id)activeMessages;
- (id)activeIndexes;
- (id)activeMessage;
- (id)messageForRow:(unsigned long long)arg1;
- (void)invalidateAllViewModels;
- (void)invalidateViewModelForMessage:(id)arg1;
- (id)viewModelForMessage:(id)arg1;
- (id)viewModelForRow:(long long)arg1;
- (void)refreshRows:(id)arg1 heightChange:(BOOL)arg2 reloadData:(BOOL)arg3;
- (void)refresh;
- (void)scheduleRefresh;
- (void)refreshMessages:(id)arg1;
- (void)refreshRowForMessage:(id)arg1;
- (void)userUpdated:(id)arg1;
- (void)messageUpdated:(id)arg1;
- (void)updateFontSize:(id)arg1;
- (void)didClickEmbedView:(id)arg1;
- (id)messageForEmbedView:(id)arg1;
- (id)tableView:(id)arg1 menuForRow:(long long)arg2;
- (void)tableView:(id)arg1 didClickRow:(long long)arg2 inView:(id)arg3 event:(id)arg4;
- (BOOL)tableView:(id)arg1 writeRowsWithIndexes:(id)arg2 toPasteboard:(id)arg3;
- (id)tableView:(id)arg1 pasteboardWriterForRow:(long long)arg2;
- (BOOL)tableView:(id)arg1 acceptDrop:(id)arg2 row:(long long)arg3 dropOperation:(unsigned long long)arg4;
- (unsigned long long)tableView:(id)arg1 validateDrop:(id)arg2 proposedRow:(long long)arg3 proposedDropOperation:(unsigned long long)arg4;
- (double)tableView:(id)arg1 heightOfRow:(long long)arg2;
- (id)tableView:(id)arg1 viewForTableColumn:(id)arg2 row:(long long)arg3;
- (id)tableView:(id)arg1 rowViewForRow:(long long)arg2;
- (long long)numberOfRowsInTableView:(id)arg1;
- (void)updateFindIndicatorWithMessage:(id)arg1;
- (void)viewDidChangeFrame:(id)arg1;
- (id)userForMessage:(id)arg1;
- (BOOL)isUserAccount:(id)arg1;
- (void)unstarMessage:(id)arg1;
- (void)starMessage:(id)arg1;
- (void)toggleInlineImages:(id)arg1;
- (void)toggleEnterLeaveMessages:(id)arg1;
- (BOOL)validateMenuItem:(id)arg1;
- (id)messages;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)viewWillClose;
- (void)awakeFromNib;
- (id)initWithRoom:(id)arg1 account:(id)arg2;
- (void)dealloc;

@end

@protocol FlintPasteboardHandlerDelegate <NSObject>

@optional
- (void)uploadFiles:(NSArray *)arg1;
@end

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

@interface FlintRoomController : FlintViewController <FlintCampfireRoomConnectionDelegate, FlintPasteboardHandlerDelegate, FlintInputDelegate>
{
    FlintCampfireRoom *_room;
    BOOL _loadingEarlierMessages;
    FlintUsersController *_usersController;
    FlintSplitView *_splitView;
    FlintUnreadCounts *_unreadCounts;
    FlintMessagesViewController *_messagesController;
    FlintCampfireRoomConnection *_connection;
    FlintBottomViewController *_bottomViewController;
    NSMutableSet *_postedMessages;
    long long _postingQueue;
    FlintAccount *_account;
    NSMenu *_recentUploads;
    BOOL _awake;
    FlintMessagesCollection *_messagesCollection;
    NSView *_sidebarView;
    BOOL _reloading;
    BOOL _hasLoadedEarlierMessages;
    NSView *_mainView;
    NSPopover *_popover;
}

@property(retain) NSPopover *popover; // @synthesize popover=_popover;
@property __weak NSView *mainView; // @synthesize mainView=_mainView;
@property BOOL hasLoadedEarlierMessages; // @synthesize hasLoadedEarlierMessages=_hasLoadedEarlierMessages;
@property BOOL reloading; // @synthesize reloading=_reloading;
@property __weak NSView *sidebarView; // @synthesize sidebarView=_sidebarView;
@property(readonly) FlintMessagesCollection *messagesCollection; // @synthesize messagesCollection=_messagesCollection;
@property BOOL awake; // @synthesize awake=_awake;
@property(retain) NSMenu *recentUploads; // @synthesize recentUploads=_recentUploads;
@property(readonly) FlintAccount *account; // @synthesize account=_account;
@property long long postingQueue; // @synthesize postingQueue=_postingQueue;
@property(retain) NSMutableSet *postedMessages; // @synthesize postedMessages=_postedMessages;
@property(retain) FlintBottomViewController *bottomViewController; // @synthesize bottomViewController=_bottomViewController;
@property(retain) FlintCampfireRoomConnection *connection; // @synthesize connection=_connection;
@property(retain) FlintMessagesViewController *messagesController; // @synthesize messagesController=_messagesController;
@property(retain) FlintUnreadCounts *unreadCounts; // @synthesize unreadCounts=_unreadCounts;
@property __weak FlintSplitView *splitView; // @synthesize splitView=_splitView;
@property(retain) FlintUsersController *usersController; // @synthesize usersController=_usersController;
@property BOOL loadingEarlierMessages; // @synthesize loadingEarlierMessages=_loadingEarlierMessages;
@property(readonly) FlintCampfireRoom *room; // @synthesize room=_room;
- (double)splitView:(id)arg1 constrainSplitPosition:(double)arg2 ofSubviewAt:(long long)arg3;
- (double)splitView:(id)arg1 constrainMaxCoordinate:(double)arg2 ofSubviewAt:(long long)arg3;
- (double)splitView:(id)arg1 constrainMinCoordinate:(double)arg2 ofSubviewAt:(long long)arg3;
- (BOOL)splitView:(id)arg1 shouldHideDividerAtIndex:(long long)arg2;
- (BOOL)splitView:(id)arg1 shouldCollapseSubview:(id)arg2 forDoubleClickOnDividerAtIndex:(long long)arg3;
- (BOOL)splitView:(id)arg1 canCollapseSubview:(id)arg2;
- (BOOL)splitView:(id)arg1 shouldAdjustSizeOfSubview:(id)arg2;
- (void)splitViewDidResizeSubviews:(id)arg1;
- (void)sidebarResized:(id)arg1;
- (void)showErrorWithMessage:(id)arg1;
- (id)containerView;
- (void)insertBottomView;
- (void)postMessageNotification:(id)arg1;
- (void)updatedEnterLeaveMessages:(id)arg1;
- (void)accountsUpdated:(id)arg1;
- (void)loadEarlierMessages:(id)arg1;
- (void)clearBacklog:(id)arg1;
- (void)toggleUsers:(id)arg1;
- (void)handleOpenUpload:(id)arg1;
- (void)mute:(id)arg1;
- (void)viewTranscript:(id)arg1;
- (void)toggleRoomLock:(id)arg1;
- (void)leave:(id)arg1;
- (void)openRoomInBrowser:(id)arg1;
- (void)insertUser:(id)arg1;
- (void)changeRoomTopic:(id)arg1;
- (void)reloadRoom:(id)arg1;
- (void)clearUnreadCounts;
- (void)handleNotifications:(id)arg1;
- (void)fetchRoomInfo;
- (void)processMessage:(id)arg1 streamed:(BOOL)arg2;
- (void)connectionErrorOccurred:(id)arg1;
- (void)connectionDidConnect;
- (void)connectionDidReceiveMessages:(id)arg1 streamed:(BOOL)arg2;
- (void)reconnect;
- (void)reconnectRoomNotification:(id)arg1;
- (void)disconnect;
- (void)disconnectRoomNotification:(id)arg1;
- (void)connect;
- (void)fetchUploadForMessage:(id)arg1;
- (void)roomDidFetchRecentUploads;
- (void)fetchRecentUploads;
- (void)uploadFiles:(id)arg1;
- (void)uploadFile:(id)arg1;
- (void)postMessage:(id)arg1 paste:(BOOL)arg2;
- (void)unlockRoom;
- (void)lockRoom;
- (void)updateRoomTitle;
- (id)windowTitle;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (BOOL)validateMenuItem:(id)arg1;
- (void)keyDown:(id)arg1;
- (id)supplementalTargetForAction:(SEL)arg1 sender:(id)arg2;
- (void)paste:(id)arg1;
- (void)viewWillClose;
- (void)windowWillClose;
- (void)viewWillDisappear;
- (void)viewDidBecomeActive;
- (void)awakeFromNib;
- (id)description;
- (id)initWithRoom:(id)arg1;
- (void)dealloc;

@end

@interface FlintRoomSettings : NSObject <NSCoding>
{
    NSMutableDictionary *_preferences;
}

@property(retain) NSMutableDictionary *preferences; // @synthesize preferences=_preferences;
- (BOOL)isMuted;
- (void)setMuted:(BOOL)arg1;
- (void)setSidebarWidth:(long long)arg1;
- (long long)sidebarWidth;
- (void)setShowInlineImages:(BOOL)arg1;
- (BOOL)showInlineImages;
- (void)setShowStatusMessages:(BOOL)arg1;
- (BOOL)showStatusMessages;
- (unsigned long long)lastMessageId;
- (void)setLastMessageId:(unsigned long long)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (void)dealloc;

@end

@interface FlintSplitView : NSSplitView
{
    BOOL _dragged;
}

@property BOOL dragged; // @synthesize dragged=_dragged;
- (void)mouseDown:(id)arg1;

@end

@interface FlintTableView : NSTableView
{
    long long _flintClickedRow;
}

@property long long flintClickedRow; // @synthesize flintClickedRow=_flintClickedRow;
- (void)drawGridInClipRect:(struct CGRect)arg1;
- (long long)clickedRow;
- (id)menuForEvent:(id)arg1;
- (void)rightMouseDown:(id)arg1;
- (void)mouseDown:(id)arg1;
- (BOOL)validateProposedFirstResponder:(id)arg1 forEvent:(id)arg2;

@end

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

@interface FlintTweet : NSObject
{
    NSString *_link;
    NSURL *_avatarURL;
    NSImage *_avatar;
    NSString *_username;
    NSString *_message;
}

@property(copy) NSString *message; // @synthesize message=_message;
@property(copy) NSString *username; // @synthesize username=_username;
@property(retain) NSImage *avatar; // @synthesize avatar=_avatar;
@property(copy) NSURL *avatarURL; // @synthesize avatarURL=_avatarURL;
@property(copy) NSString *link; // @synthesize link=_link;
- (void)fetchAvatar;
- (id)initWithDict:(id)arg1;
- (id)init;

@end

@interface FlintUnreadCounts : NSObject
{
    unsigned long long _tabCount;
    unsigned long long _menuBarCount;
    unsigned long long _dockBadgeCount;
}

@property(nonatomic) unsigned long long dockBadgeCount; // @synthesize dockBadgeCount=_dockBadgeCount;
@property(nonatomic) unsigned long long menuBarCount; // @synthesize menuBarCount=_menuBarCount;
@property(nonatomic) unsigned long long tabCount; // @synthesize tabCount=_tabCount;
- (void)reset;
- (id)init;

@end

@class FlintRoomController;

@interface FlintUsersController : NSViewController <NSTableViewDelegate, NSTableViewDataSource>
{
    FlintRoomController *_roomController;
    NSTableView *_tableView;
    NSArray *_users;
    int _tableSize;
}

@property int tableSize; // @synthesize tableSize=_tableSize;
@property(retain, nonatomic) NSArray *users; // @synthesize users=_users;
@property(nonatomic) __weak NSTableView *tableView; // @synthesize tableView=_tableView;
@property(nonatomic) FlintRoomController *roomController; // @synthesize roomController=_roomController;
- (void)refreshUser:(id)arg1;
- (id)activeIndexes;
- (void)doubleClickedRow:(id)arg1;
- (void)tableViewColumnDidResize:(id)arg1;
- (id)tableView:(id)arg1 viewForTableColumn:(id)arg2 row:(long long)arg3;
- (long long)numberOfRowsInTableView:(id)arg1;
- (void)refresh:(id)arg1;
- (void)awakeFromNib;
- (id)init;
- (void)dealloc;

@end

@interface FlintWindowController : NSWindowController <NSWindowDelegate, NSTabViewDelegate>
{
    BOOL _tabsEnabled;
    NSDictionary *_config;
    NSView *_trialView;
    NSTabView *_tabView;
    NSButton *_trialRemaining;
    NSMutableArray *_viewControllers;
    NSDate *_lastActivated;
    /*PSMTabBarControl*/void *_tabBar;
}

+ (void)loadTranscriptForRoom:(id)arg1;
+ (id)windowController;
//@property __weak PSMTabBarControl *tabBar; // @synthesize tabBar=_tabBar;
@property(retain) NSDate *lastActivated; // @synthesize lastActivated=_lastActivated;
@property(retain) NSMutableArray *viewControllers; // @synthesize viewControllers=_viewControllers;
@property __weak NSButton *trialRemaining; // @synthesize trialRemaining=_trialRemaining;
@property __weak NSTabView *tabView; // @synthesize tabView=_tabView;
@property __weak NSView *trialView; // @synthesize trialView=_trialView;
@property(retain) NSDictionary *config; // @synthesize config=_config;
@property BOOL tabsEnabled; // @synthesize tabsEnabled=_tabsEnabled;
- (void)addBetaToWindow;
- (void)openWebsite:(id)arg1;
- (void)addTrialToWindow;
- (id)tabView:(id)arg1 toolTipForTabViewItem:(id)arg2;
- (id)tabView:(id)arg1 newTabBarForDraggedTabViewItem:(id)arg2 atPoint:(struct CGPoint)arg3;
- (void)tabView:(id)arg1 didDropTabViewItem:(id)arg2 inTabBar:(id)arg3;
- (BOOL)tabView:(id)arg1 shouldDropTabViewItem:(id)arg2 inTabBar:(id)arg3;
- (BOOL)tabView:(id)arg1 shouldDragTabViewItem:(id)arg2 fromTabBar:(id)arg3;
- (id)tabView:(id)arg1 menuForTabViewItem:(id)arg2;
- (id)allowedDraggedTypesForTabView:(id)arg1;
- (void)tabView:(id)arg1 didCloseTabViewItem:(id)arg2;
- (void)tabView:(id)arg1 didSelectTabViewItem:(id)arg2;
- (void)switchTabs:(id)arg1;
- (void)closeViewController:(id)arg1;
- (void)closeTabItem:(id)arg1;
- (void)addViewController:(id)arg1 forTab:(id)arg2;
- (void)selectTabForViewController:(id)arg1;
- (void)selectTabAtIndex:(unsigned long long)arg1;
- (void)selectPreviousTab:(id)arg1;
- (void)selectNextTab:(id)arg1;
- (void)addTabForViewController:(id)arg1 activate:(BOOL)arg2;
- (void)addTabForViewController:(id)arg1;
- (void)newTab:(id)arg1;
- (void)didUpdateTabPosition:(id)arg1;
- (void)updateWindowTitle;
- (void)loadSearchForAccount:(id)arg1;
- (void)loadTranscriptForRoom:(id)arg1 withDate:(id)arg2 message:(id)arg3 highlight:(id)arg4;
- (void)loadTranscriptForRoom:(id)arg1 withDate:(id)arg2 message:(id)arg3;
- (void)loadTranscriptForRoom:(id)arg1 withDate:(id)arg2;
- (void)loadTranscriptForRoom:(id)arg1;
- (void)activateRoomWithRoomId:(unsigned long long)arg1;
- (BOOL)hasRoom:(id)arg1;
- (int)actualRoomCount;
- (void)loadRoom:(id)arg1 inViewController:(id)arg2;
- (void)loadRoom:(id)arg1 background:(BOOL)arg2;
- (void)loadRoom:(id)arg1 newWindow:(BOOL)arg2;
- (void)loadRoom:(id)arg1;
- (void)loadLobbyInViewController:(id)arg1;
- (void)loadLobby;
- (BOOL)hasOpenRooms;
- (void)replaceViewController:(id)arg1 withViewController:(id)arg2 direction:(id)arg3;
- (id)viewControllerForTab:(id)arg1;
- (BOOL)isViewControllerActive:(id)arg1;
- (id)activeViewController;
- (void)forceClose:(id)arg1;
- (void)close:(id)arg1;
- (void)hideWindow;
- (id)windowConfig;
- (void)restoreFromConfig;
- (BOOL)validateMenuItem:(id)arg1;
- (id)supplementalTargetForAction:(SEL)arg1 sender:(id)arg2;
- (void)resetTextSize:(id)arg1;
- (void)decreaseTextSize:(id)arg1;
- (void)increaseTextSize:(id)arg1;
- (void)windowWillClose:(id)arg1;
- (BOOL)windowShouldClose:(id)arg1;
- (void)windowDidBecomeMain:(id)arg1;
- (void)windowDidBecomeKey:(id)arg1;
- (void)awakeFromNib;
- (id)description;
- (id)init;
- (void)dealloc;

@end

@interface FCFAccount : NSObject <NSCoding>
{
    NSString *_subdomain;
    NSString *_plan;
    NSTimeZone *_timezone;
    long long _storage;
    NSString *_name;
    unsigned long long _uid;
}

@property(readonly) unsigned long long uid; // @synthesize uid=_uid;
@property(readonly) NSString *name; // @synthesize name=_name;
@property(readonly) long long storage; // @synthesize storage=_storage;
@property(readonly) NSTimeZone *timezone; // @synthesize timezone=_timezone;
@property(readonly) NSString *plan; // @synthesize plan=_plan;
@property(readonly) NSString *subdomain; // @synthesize subdomain=_subdomain;
- (id)description;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithDictionary:(id)arg1;

@end

@interface FlintCampfireRoomConnection : NSObject <NSURLConnectionDelegate>
{
    BOOL _streaming;
    NSDate *_lastJoin;
    NSTimer *_pingTimer;
    NSTimer *_timeout;
    NSTimer *_pollTimer;
    BOOL _initialFetch;
    id <FlintCampfireRoomConnectionDelegate> _delegate;
    FlintAccount *_account;
    NSURLConnection *_streamingConnection;
    BOOL _fetching;
    FlintCampfireRoom *_room;
    int _state;
    FlintCampfireMessage *_lastMessage;
    NSMutableString *_buffer;
    NSDate *_lastUpdate;
}

+ (id)streamingURL;
@property(retain) NSDate *lastUpdate; // @synthesize lastUpdate=_lastUpdate;
@property(retain) NSMutableString *buffer; // @synthesize buffer=_buffer;
@property(retain) FlintCampfireMessage *lastMessage; // @synthesize lastMessage=_lastMessage;
@property(nonatomic) int state; // @synthesize state=_state;
@property(readonly) FlintCampfireRoom *room; // @synthesize room=_room;
@property BOOL fetching; // @synthesize fetching=_fetching;
@property(retain) NSURLConnection *streamingConnection; // @synthesize streamingConnection=_streamingConnection;
@property(readonly) FlintAccount *account; // @synthesize account=_account;
@property id <FlintCampfireRoomConnectionDelegate> delegate; // @synthesize delegate=_delegate;
@property BOOL initialFetch; // @synthesize initialFetch=_initialFetch;
@property(retain) NSTimer *pollTimer; // @synthesize pollTimer=_pollTimer;
@property(retain) NSTimer *timeout; // @synthesize timeout=_timeout;
@property(retain) NSTimer *pingTimer; // @synthesize pingTimer=_pingTimer;
@property(retain) NSDate *lastJoin; // @synthesize lastJoin=_lastJoin;
@property BOOL streaming; // @synthesize streaming=_streaming;
- (void)networkUnavailable:(id)arg1;
- (void)networkAvailable:(id)arg1;
- (void)ping;
- (void)sendPing:(id)arg1;
- (void)clearPing;
- (void)startPing;
- (void)fetchRecentMessages;
- (void)fetchInitialMessages;
- (void)stopPolling;
- (void)pollTimerDidFire:(id)arg1;
- (void)startPolling;
- (void)resetTimeout;
- (void)clearTimeout;
- (void)addTimeout;
- (void)streamDidTimeout:(id)arg1;
- (void)connectionDidFinishLoading:(id)arg1;
- (void)connection:(id)arg1 didFailWithError:(id)arg2;
- (void)connection:(id)arg1 didReceiveData:(id)arg2;
- (void)connection:(id)arg1 didReceiveResponse:(id)arg2;
- (void)processStreamData:(id)arg1;
- (void)clearStreamingConnection;
- (void)stopStreaming;
- (void)startStreaming;
- (void)processMessages:(id)arg1 streamed:(BOOL)arg2;
- (double)minutesSinceLastJoin;
- (double)secondsSinceLastUpdate;
- (void)disconnect;
- (void)reconnect;
- (void)connect;
- (BOOL)isDisconnected;
- (BOOL)isConnected;
- (id)description;
- (id)initWithRoom:(id)arg1 account:(id)arg2;
- (void)dealloc;

@end

@interface FlintAccount : NSObject <NSCoding>
{
    NSString *_apiToken;
    FCFAccount *_account;
    NSString *_url;
    FlintCampfireClient *_client;
    NSString *_accessToken;
    unsigned long long _userId;
    NSString *_name;
    NSMutableArray *_rooms;
    NSMutableDictionary *_users;
    NSString *_userName;
    NSMutableDictionary *_fetching;
    NSString *_domain;
}

+ (void)fetchAuthorizationWithAccessToken:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
+ (void)fetchAccountsUsingVerificationCode:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
+ (id)accountWithKey:(id)arg1;
+ (id)accountForRoomId:(unsigned long long)arg1;
+ (id)accountForRoom:(id)arg1;
+ (id)accountWithDomain:(id)arg1;
+ (void)moveAccountAtIndex:(unsigned long long)arg1 toIndex:(unsigned long long)arg2;
+ (void)clearAccounts;
+ (void)setAccounts:(id)arg1;
+ (void)saveAccounts;
+ (void)removeAccount:(id)arg1;
+ (void)addAccount:(id)arg1;
+ (void)loadAccounts;
+ (id)accounts;
@property(copy) NSString *domain; // @synthesize domain=_domain;
@property(retain) NSMutableDictionary *fetching; // @synthesize fetching=_fetching;
@property(copy) NSString *userName; // @synthesize userName=_userName;
@property(retain, nonatomic) NSMutableDictionary *users; // @synthesize users=_users;
@property(retain) NSMutableArray *rooms; // @synthesize rooms=_rooms;
@property(copy) NSString *name; // @synthesize name=_name;
@property unsigned long long userId; // @synthesize userId=_userId;
@property(copy) NSString *accessToken; // @synthesize accessToken=_accessToken;
@property(retain, nonatomic) FlintCampfireClient *client; // @synthesize client=_client;
@property(copy) NSString *url; // @synthesize url=_url;
@property(retain) FCFAccount *account; // @synthesize account=_account;
@property(copy) NSString *apiToken; // @synthesize apiToken=_apiToken;
- (id)URLForRoom:(id)arg1;
- (id)roomForRoomId:(unsigned long long)arg1;
- (void)fetchUser:(id)arg1;
- (id)nonfetchingUserforUserId:(unsigned long long)arg1;
- (id)userForUserId:(unsigned long long)arg1;
- (id)user;
- (void)updateFromAccount:(id)arg1;
- (id)retrieveTokenFromKeychain;
- (void)removeTokenFromKeychain;
- (void)saveTokenToKeychain;
- (id)accountKey;
- (void)fetchAccount:(CDUnknownBlockType)arg1;
- (void)fetchRoomsUsingBlock:(CDUnknownBlockType)arg1;
- (BOOL)isEqualToAccount:(id)arg1;
- (id)description;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end
