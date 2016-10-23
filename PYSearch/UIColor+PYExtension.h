//
//  UIColor+PYExtension.h
//  PYSearchViewControllerExample
//
//  Created by 谢培艺 on 2016/10/21.
//  Copyright © 2016年 CoderKo1o. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (PYExtension)
/** 根据16进制字符串返回对应颜色 */
+ (instancetype)py_colorWithHexString:(NSString *)hexString;

/** 根据16进制字符串返回对应颜色 带透明参数 */
+ (instancetype)py_colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;

@end
