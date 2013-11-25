#include <stdio.h>
#include "flint/FlintAppDelegate.h"

static FlintAppDelegate* flint;

static sig_t old_sigalrm;

static void
flint_plus_init()
{
    signal(SIGALRM, old_sigalrm);

    flint = (FlintAppDelegate*)[NSApplication sharedApplication].delegate;

    [flint showAbout: nil];

    fprintf(stderr, "FlintPlus loaded!\n");
}

__attribute__((constructor)) void
flint_plus_main()
{
    old_sigalrm = signal(SIGALRM, flint_plus_init);
    alarm(1);
}
