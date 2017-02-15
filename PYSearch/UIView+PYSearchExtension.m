// 
//  代码地址: https://github.com/iphone5solo/PYSearch
//  代码地址: http://www.code4app.com/thread-11175-1-1.html
//  Created by CoderKo1o.
//  Copyright © 2016年 iphone5solo. All rights reserved.
//

#import "UIView+PYSearchExtension.h"

@implementation UIView (PYSearchExtension)

- (void)setPy_x:(CGFloat)py_x
{
    CGRect frame = self.frame;
    frame.origin.x = py_x;
    self.frame = frame;
}

- (CGFloat)py_x
{
    return self.py_origin.x;
}

- (void)setPy_centerX:(CGFloat)py_centerX
{
    CGPoint center = self.center;
    center.x = py_centerX;
    self.center = center;
}

- (CGFloat)py_centerX
{
    return self.center.x;
}

-(void)setPy_centerY:(CGFloat)py_centerY
{
    CGPoint center = self.center;
    center.y = py_centerY;
    self.center = center;
}

- (CGFloat)py_centerY
{
    return self.center.y;
}

- (void)setPy_y:(CGFloat)py_y
{
    CGRect frame = self.frame;
    frame.origin.y = py_y;
    self.frame = frame;
}

- (CGFloat)py_y
{
    return self.frame.origin.y;
}

- (void)setPy_size:(CGSize)py_size
{
    CGRect frame = self.frame;
    frame.size = py_size;
    self.frame = frame;

}

- (CGSize)py_size
{
    return self.frame.size;
}

- (void)setPy_height:(CGFloat)py_height
{
    CGRect frame = self.frame;
    frame.size.height = py_height;
    self.frame = frame;
}

- (CGFloat)py_height
{
    return self.frame.size.height;
}

- (void)setPy_width:(CGFloat)py_width
{
    CGRect frame = self.frame;
    frame.size.width = py_width;
    self.frame = frame;

}

-(CGFloat)py_width
{
    return self.frame.size.width;
}

- (void)setPy_origin:(CGPoint)py_origin
{
    CGRect frame = self.frame;
    frame.origin = py_origin;
    self.frame = frame;
}

- (CGPoint)py_origin
{
    return self.frame.origin;
}

@end
