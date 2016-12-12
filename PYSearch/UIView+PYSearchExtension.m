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
- (CGFloat)py_width
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

/** 设置锚点 */
- (CGPoint)py_setAnchorPoint:(CGPoint)anchorPoint forView:(UIView *)view
{
    CGPoint oldOrigin = view.frame.origin;
    view.layer.anchorPoint = anchorPoint;
    CGPoint newOrigin = view.frame.origin;
    
    CGPoint transition;
    transition.x = newOrigin.x - oldOrigin.x;
    transition.y = newOrigin.y - oldOrigin.y;
    
    view.center = CGPointMake (view.center.x - transition.x, view.center.y - transition.y);
    return self.layer.anchorPoint;
}

/** 根据手势触摸点修改相应的锚点，就是沿着触摸点做相应的手势操作 */
- (CGPoint)py_setAnchorPointBaseOnGestureRecognizer:(UIGestureRecognizer *)gr
{
    // 手势为空 直接返回
    if (!gr) return CGPointMake(0.5, 0.5);
    
    // 创建锚点
    CGPoint anchorPoint;
    if ([gr isKindOfClass:[UIPinchGestureRecognizer class]]) { // 捏合手势
        if (gr.numberOfTouches == 2) {
            // 当触摸开始时，获取两个触摸点
            CGPoint point1 = [gr locationOfTouch:0 inView:gr.view];
            CGPoint point2 = [gr locationOfTouch:1 inView:gr.view];
            anchorPoint.x = (point1.x + point2.x) / 2 / gr.view.py_width;
            anchorPoint.y = (point1.y + point2.y) / 2 / gr.view.py_height;
        }
    } else if ([gr isKindOfClass:[UITapGestureRecognizer class]]) { // 点击手势
        // 获取触摸点
        CGPoint point = [gr locationOfTouch:0 inView:gr.view];
        
        CGFloat angle = acosf(gr.view.transform.a);
        if (ABS(asinf(gr.view.transform.b) + M_PI_2) < 0.01) angle += M_PI;
        CGFloat width = gr.view.py_width;
        CGFloat height = gr.view.py_height;
        if (ABS(angle - M_PI_2) <= 0.01 || ABS(angle - M_PI_2 * 3) <= 0.01) { // 旋转角为90°
            // width 和 height 对换
            width = gr.view.py_height;
            height = gr.view.py_width;
        }
        // 如果旋转了
        anchorPoint.x = point.x / width;
        anchorPoint.y = point.y / height;
    };
    return [self py_setAnchorPoint:anchorPoint forView:self];
}
@end
