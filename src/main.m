#include <stdio.h>
#include <objc/runtime.h>
#include "flint/FlintAppDelegate.h"
#include "flint/FlintTextView.h"
#include "hackery.h"

FlintAppDelegate*
flint;

@interface flint_plus_FlintAppDelegate : NSObject
- original_showAbout:(id)arg1;
@end

@implementation flint_plus_FlintAppDelegate
- (void)showAbout:(id)arg1
{
    printf("showing about!\n");
    [self original_showAbout: arg1];
}
@end

static void
flint_plus_init()
{
    flint = (FlintAppDelegate*)[NSApplication sharedApplication].delegate;

    flint_plus_patch("FlintAppDelegate", "showAbout:");

    [flint showAbout: nil];

    fprintf(stderr, "FlintPlus loaded!\n");
}

static sig_t old_sigalrm;

static void
sigalrm()
{
    signal(SIGALRM, old_sigalrm);
    flint_plus_init();
}

__attribute__((constructor)) void
flint_plus_main()
{
    old_sigalrm = signal(SIGALRM, sigalrm);
    alarm(1);
}
