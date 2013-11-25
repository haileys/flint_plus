#import <Foundation/Foundation.h>

id
flint_plus_get_fake_ivar(id object, NSString* name);

void
flint_plus_set_fake_ivar(id object, NSString* name, id value);

void
flint_plus_fake_ivar_dealloc(id object);
