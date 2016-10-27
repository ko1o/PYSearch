// 
//  代码地址: https://github.com/iphone5solo/PYSearch
//  代码地址: http://www.code4app.com/thread-11175-1-1.html
//  Created by CoderKo1o.
//  Copyright © 2016年 iphone5solo. All rights reserved.
//  UIColor 分类

#import <UIKit/UIKit.h>

@interface UIColor (PYExtension)
/** 根据16进制字符串返回对应颜色 */
+ (instancetype)py_colorWithHexString:(NSString *)hexString;

/** 根据16进制字符串返回对应颜色 带透明参数 */
+ (instancetype)py_colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;

@end
