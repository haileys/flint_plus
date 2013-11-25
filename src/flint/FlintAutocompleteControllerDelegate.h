#import "FlintAutocompleteItem.h"

@protocol FlintAutocompleteControllerDelegate <NSObject>
- (void)insertAutocompleteItem:(FlintAutocompleteItem *)arg1;
- (void)continueAutocompleteWithString:(NSString *)arg1;
@end
