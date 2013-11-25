#include <stdio.h>
#include "flint/FlintAppDelegate.h"

FlintAppDelegate*
flint;

static void
flint_plus_init()
{
    flint = (FlintAppDelegate*)[NSApplication sharedApplication].delegate;

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
