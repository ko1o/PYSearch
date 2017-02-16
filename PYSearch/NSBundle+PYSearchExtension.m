//
//  代码地址: https://github.com/iphone5solo/PYSearch
//  代码地址: http://www.code4app.com/thread-11175-1-1.html
//  Created by CoderKo1o.
//  Copyright © 2016年 iphone5solo. All rights reserved.
//  

#import "NSBundle+PYSearchExtension.h"
#import "PYSearchViewController.h"

@implementation NSBundle (PYSearchExtension)

/** 获取PYSearch.bundle路径 */
+ (NSBundle *)py_searchBundle
{
    static NSBundle *searchBundle = nil;
    if (searchBundle == nil) {
        // 默认使用[NSBundle mainBundle]
        searchBundle = [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"PYSearch" ofType:@"bundle"]];
        // 如果使用pod导入，并且在Podfile中配置use_frameworks!则[NSBundle mainBundle] 加载不到PYSearch.framework中的PYSearch.bundle资源文件
        if (searchBundle == nil) { // 为空说明资源文件在PYSearch.framework中
            searchBundle = [NSBundle bundleWithPath:[[NSBundle bundleForClass:[PYSearchViewController class]] pathForResource:@"PYSearch" ofType:@"bundle"]];
        }
    }
    return searchBundle;
}

+ (NSString *)py_localizedStringForKey:(NSString *)key;
{
    return [self py_localizedStringForKey:key value:nil];
}

+ (NSString *)py_localizedStringForKey:(NSString *)key value:(NSString *)value
{
    static NSBundle *bundle = nil;
    if (bundle == nil) {
        // 只处理en、zh-Hans、zh-Hant三种情况，其他按照系统默认处理
        NSString *language = [NSLocale preferredLanguages].firstObject;
        if ([language hasPrefix:@"en"]) language = @"en";
        else if ([language hasPrefix:@"es"]) language = @"es";
        else if ([language hasPrefix:@"fr"]) language = @"fr";
        else if ([language hasPrefix:@"zh"]) {
            if ([language rangeOfString:@"Hans"].location != NSNotFound) {
                language = @"zh-Hans"; // 简体中文
            } else { // zh-Hant\zh-HK\zh-TW
                language = @"zh-Hant"; // 繁體中文
            }
        } else {
            language = @"en";
        }
        
        // 从PYSearch.bundle中查找资源
        bundle = [NSBundle bundleWithPath:[[NSBundle py_searchBundle] pathForResource:language ofType:@"lproj"]];
    }
    value = [bundle localizedStringForKey:key value:value table:nil];
    return [[NSBundle mainBundle] localizedStringForKey:key value:value table:nil];
}
    
+ (UIImage *)py_imageNamed:(NSString *)name
{
    // 判断分辨率，设置图片名称
    CGFloat scale = [[UIScreen mainScreen] scale];
    name = scale == 3.0 ? [NSString stringWithFormat:@"%@@3x.png", name] : [NSString stringWithFormat:@"%@@2x.png", name];
    UIImage *image = [UIImage imageWithContentsOfFile:[[[NSBundle py_searchBundle] resourcePath] stringByAppendingPathComponent:name]];
    return image;
}

@end
