//
//  GitHub: https://github.com/iphone5solo/PYSearch
//  Created by CoderKo1o.
//  Copyright © 2016 iphone5solo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSBundle (PYSearchExtension)

/**
 Get the localized string

 @param key     key for localized string
 @return a localized string
 */
+ (NSString *)py_localizedStringForKey:(NSString *)key;

/**
 Get the path of `PYSearch.bundle`.

 @return path of the `PYSearch.bundle`
 */
+ (NSBundle *)py_searchBundle;

/**
 Get the image in the `PYSearch.bundle` path

 @param name name of image
 @return a image
 */
+ (UIImage *)py_imageNamed:(NSString *)name;

@end
