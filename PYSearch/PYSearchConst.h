// 
//  代码地址: https://github.com/iphone5solo/PYSearch
//  代码地址: http://www.code4app.com/thread-11175-1-1.html
//  Created by CoderKo1o.
//  Copyright © 2016年 iphone5solo. All rights reserved.
//  用于存储常量、宏定义的头文件

#import <UIKit/UIKit.h>
#import "UIView+PYExtension.h"
#import "UIColor+PYExtension.h"

#define PYMargin 10 // 默认边距
#define PYBackgroundColor PYColor(255, 255, 255) // tableView背景颜色

// 日志输出
#ifdef DEBUG
#define PYSearchLog(...) NSLog(__VA_ARGS__)
#else
#define PYSearchLog(...)
#endif

// 颜色
#define PYColor(r,g,b) [UIColor colorWithRed:(r/255.0) green:(g/255.0) blue:(b/255.0) alpha:1.0]
#define PYRandomColor  PYColor(arc4random_uniform(256),arc4random_uniform(256),arc4random_uniform(256))

// 屏幕宽高
// 屏幕宽高(注意：由于不同iOS系统下，设备横竖屏时屏幕的高度和宽度有的是变化的有的是不变的)
#define PYRealyScreenW [UIScreen mainScreen].bounds.size.width
#define PYRealyScreenH [UIScreen mainScreen].bounds.size.height
// 屏幕宽高（这里获取的是正常竖屏的屏幕宽高（宽永远小于高度））
#define PYScreenW (PYRealyScreenW < PYRealyScreenH ? PYRealyScreenW : PYRealyScreenH)
#define PYScreenH (PYRealyScreenW > PYRealyScreenH ? PYRealyScreenW : PYRealyScreenH)
#define PYScreenSize CGSizeMake(PYScreenW, PYScreenH)

#define PYSearchHistoryImage [UIImage imageNamed:@"PYSearch.bundle/search_history"] // 搜索历史Cell的图片
#define PYSearchSuggestionImage [UIImage imageNamed:@"PYSearch.bundle/search"] // 搜索建议时，Cell的图片

UIKIT_EXTERN NSString *const PYSearchPlaceholderText;   // 搜索框的占位符 默认为 @"搜索内容"
UIKIT_EXTERN NSString *const PYHotSearchText;           // 热门搜索文本 默认为 @"热门搜索"
UIKIT_EXTERN NSString *const PYSearchHistoryText;       // 搜索历史文本 默认为 @"搜索历史"
UIKIT_EXTERN NSString *const PYEmptySearchHistoryText;  // 清空搜索历史文本 默认为 @"清空搜索历史"
