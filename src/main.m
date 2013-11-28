#include <stdio.h>
#include <objc/runtime.h>
#include "flint.h"
#include "hackery.h"

FlintAppDelegate*
flint;

void
flint_plus_init_text_view();

static void
flint_plus_init()
{
    flint = (FlintAppDelegate*)[NSApplication sharedApplication].delegate;

    flint_plus_init_text_view();

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
