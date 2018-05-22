//
//  GitHub: https://github.com/iphone5solo/PYSearch
//  Created by CoderKo1o.
//  Copyright © 2016 iphone5solo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIView+PYSearchExtension.h"
#import "UIColor+PYSearchExtension.h"
#import "NSBundle+PYSearchExtension.h"

#define PYSEARCH_MARGIN 10
#define PYSEARCH_BACKGROUND_COLOR PYSEARCH_COLOR(255, 255, 255)

#ifdef DEBUG
#define PYSEARCH_LOG(...) NSLog(__VA_ARGS__)
#else
#define PYSEARCH_LOG(...)
#endif

#define PYSEARCH_COLOR(r,g,b) [UIColor colorWithRed:(r/255.0) green:(g/255.0) blue:(b/255.0) alpha:1.0]
#define PYSEARCH_RANDOM_COLOR  PYSEARCH_COLOR(arc4random_uniform(256),arc4random_uniform(256),arc4random_uniform(256))

#define PYSEARCH_DEPRECATED(instead) NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, instead)

#define PYSEARCH_REALY_SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define PYSEARCH_REALY_SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height
#define PYScreenW (PYSEARCH_REALY_SCREEN_WIDTH < PYSEARCH_REALY_SCREEN_HEIGHT ? PYSEARCH_REALY_SCREEN_WIDTH : PYSEARCH_REALY_SCREEN_HEIGHT)
#define PYScreenH (PYSEARCH_REALY_SCREEN_WIDTH > PYSEARCH_REALY_SCREEN_HEIGHT ? PYSEARCH_REALY_SCREEN_WIDTH : PYSEARCH_REALY_SCREEN_HEIGHT)
#define PYSEARCH_SCREEN_SIZE CGSizeMake(PYScreenW, PYScreenH)

#define PYSEARCH_SEARCH_HISTORY_CACHE_PATH [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:@"PYSearchhistories.plist"] // the path of search record cached

UIKIT_EXTERN NSString *const PYSearchSearchPlaceholderText;
UIKIT_EXTERN NSString *const PYSearchHotSearchText;
UIKIT_EXTERN NSString *const PYSearchSearchHistoryText;
UIKIT_EXTERN NSString *const PYSearchEmptySearchHistoryText;
UIKIT_EXTERN NSString *const PYSearchEmptyButtonText;
UIKIT_EXTERN NSString *const PYSearchEmptySearchHistoryLogText;
UIKIT_EXTERN NSString *const PYSearchCancelButtonText;
UIKIT_EXTERN NSString *const PYSearchBackButtonText;
