#import "fake_ivar.h"

static NSMutableDictionary*
fake_ivar_dict;

static NSMutableDictionary*
get_fake_ivar_dict(id object)
{
    if(fake_ivar_dict == NULL) {
        fake_ivar_dict = [NSMutableDictionary dictionary];
    }

    id key = [NSNumber numberWithInt:(int)object];

    NSMutableDictionary* dict = [fake_ivar_dict objectForKey:key];
    if(dict == nil) {
        dict = [NSMutableDictionary dictionary];
        [fake_ivar_dict setObject:dict forKey:key];
    }

    return dict;
}

id
flint_plus_get_fake_ivar(id object, NSString* name)
{
    return [get_fake_ivar_dict(object) objectForKey:name];
}

void
flint_plus_set_fake_ivar(id object, NSString* name, id value)
{
    [get_fake_ivar_dict(object) setObject:value forKey:name];
}

void
flint_plus_fake_ivar_dealloc(id object)
{
    id key = [NSNumber numberWithInt:(int)object];
    [fake_ivar_dict removeObjectForKey:key];
}
