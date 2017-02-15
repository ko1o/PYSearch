//
//  代码地址: https://github.com/iphone5solo/PYSearch
//  代码地址: http://www.code4app.com/thread-11175-1-1.html
//  Created by CoderKo1o.
//  Copyright © 2016年 iphone5solo. All rights reserved.
//  NSBundle 分类

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSBundle (PYSearchExtension)

/** 获取本地化字符串 */
+ (NSString *)py_localizedStringForKey:(NSString *)key;

/** 获取PYSearch.bundle路径 */
+ (NSBundle *)py_searchBundle;

/** 获取PYSearch.bundle路径中的图片 */
+ (UIImage *)py_imageNamed:(NSString *)name;

@end
