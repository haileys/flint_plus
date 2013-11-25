#import <AppKit/AppKit.h>

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
