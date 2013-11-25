#import <AppKit/AppKit.h>

#import "FlintAboutController.h"
#import "FlintLoginController.h"
#import "FlintLogController.h"
#import "FlintPreferencesController.h"
#import "FlintDownloadsController.h"

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
