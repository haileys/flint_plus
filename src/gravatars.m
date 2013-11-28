#import <CommonCrypto/CommonDigest.h>

#import "flint.h"
#import "hackery.h"

static NSString*
md5(NSString* str)
{
    const char* cstr = [str UTF8String];
    unsigned char digest[CC_MD5_DIGEST_LENGTH];
    CC_MD5(cstr, strlen(cstr), digest);
    NSMutableString* retn = [NSMutableString stringWithCapacity:CC_MD5_DIGEST_LENGTH*2];
    for(int i = 0; i < CC_MD5_DIGEST_LENGTH; i++) {
        [retn appendFormat:@"%02x", digest[i]];
    }
    return retn;
}

@interface flint_plus_FlintCampfireUser : NSObject
- (void)original_fetchAvatar;
@end

@implementation flint_plus_FlintCampfireUser
- (void)fetchAvatar
{
    FlintCampfireUser* user = (FlintCampfireUser*)self;
    NSString* url = [NSString stringWithFormat:@"https://secure.gravatar.com/avatar/%@", md5([user email])];
    [user setAvatarURL:[NSURL URLWithString:url]];
    [self original_fetchAvatar];
}
@end

void
flint_plus_init_gravatars()
{
    flint_plus_patch("FlintCampfireUser", "fetchAvatar");
}
