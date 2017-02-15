// 
//  代码地址: https://github.com/iphone5solo/PYSearch
//  代码地址: http://www.code4app.com/thread-11175-1-1.html
//  Created by CoderKo1o.
//  Copyright © 2016年 iphone5solo. All rights reserved.
//  用于存储常量、宏定义的头文件

#import <UIKit/UIKit.h>
#import "UIView+PYSearchExtension.h"
#import "UIColor+PYSearchExtension.h"
#import "NSBundle+PYSearchExtension.h"

#define PYSEARCH_MARGIN 10 // 默认边距
#define PYSEARCH_BACKGROUND_COLOR PYSEARCH_COLOR(255, 255, 255) // tableView背景颜色
// 日志输出
#ifdef DEBUG
#define PYSEARCH_LOG(...) NSLog(__VA_ARGS__)
#else
#define PYSEARCH_LOG(...)
#endif

// 颜色
#define PYSEARCH_COLOR(r,g,b) [UIColor colorWithRed:(r/255.0) green:(g/255.0) blue:(b/255.0) alpha:1.0]
#define PYSEARCH_RANDOM_COLOR  PYSEARCH_COLOR(arc4random_uniform(256),arc4random_uniform(256),arc4random_uniform(256))

// 屏幕宽高
// 屏幕宽高(注意：由于不同iOS系统下，设备横竖屏时屏幕的高度和宽度有的是变化的有的是不变的)
#define PYSEARCH_REALY_SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define PYSEARCH_REALY_SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height
// 屏幕宽高（这里获取的是正常竖屏的屏幕宽高（宽永远小于高度））
#define PYScreenW (PYSEARCH_REALY_SCREEN_WIDTH < PYSEARCH_REALY_SCREEN_HEIGHT ? PYSEARCH_REALY_SCREEN_WIDTH : PYSEARCH_REALY_SCREEN_HEIGHT)
#define PYScreenH (PYSEARCH_REALY_SCREEN_WIDTH > PYSEARCH_REALY_SCREEN_HEIGHT ? PYSEARCH_REALY_SCREEN_WIDTH : PYSEARCH_REALY_SCREEN_HEIGHT)
#define PYSEARCH_SCREEN_SIZE CGSizeMake(PYScreenW, PYScreenH)

#define PYSEARCH_SEARCH_HISTORY_CACHE_PATH [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:@"PYSearchhistories.plist"] // 搜索历史存储路径

UIKIT_EXTERN NSString *const PYSearchSearchPlaceholderText;     // 搜索框的占位符 默认为 @"搜索内容"
UIKIT_EXTERN NSString *const PYSearchHotSearchText;             // 热门搜索文本 默认为 @"热门搜索"
UIKIT_EXTERN NSString *const PYSearchSearchHistoryText;         // 搜索历史文本 默认为 @"搜索历史"
UIKIT_EXTERN NSString *const PYSearchEmptySearchHistoryText;    // 清空搜索历史文本 默认为 @"清空搜索历史"

UIKIT_EXTERN NSString *const PYSearchEmptyButtonText;           // 清空按钮文本，默认为 @"清空"
UIKIT_EXTERN NSString *const PYSearchEmptySearchHistoryLogText; // 清空搜索历史打印文本，默认为 @"清空搜索历史"
UIKIT_EXTERN NSString *const PYSearchCancelButtonText;          // 取消按钮位文本，默认为 @"取消"


