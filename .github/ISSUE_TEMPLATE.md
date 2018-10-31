<!-- 
您并不需要严格按照此模版提 ISSUE，只是为了方便提供相关信息，并不是为了设置障碍。
如果你觉得麻烦，也可以直接按照自己的方式来提 ISSUE。
这里非常希望您尽量多提供一些相关信息。
-->
### 问题描述
<!--
示例：
搜索类型设置为 `PYHotSearchStyleRankTag` 或者 `PYHotSearchStyleRectangleTag`, 
并在代理类中实现对应代理方法，点击热门搜索时无法执行代理方法。
-->
#### 重现步骤
<!--
示例：
1、搜索类型设置为 `PYHotSearchStyleRankTag` 或者 `PYHotSearchStyleRectangleTag`
2、在代理类中实现如下代理方法：
```objective-c
- (void)searchViewController:(PYSearchViewController *)searchViewController
   didSelectHotSearchAtIndex:(NSInteger)index
                  searchText:(NSString *)searchText
{
    NSLog(@"代理方法被调用");
}
```
-->



#### 预期结果
<!--
示例：
程序正常执行，并在控制台输出`代理方法被调用`
-->



#### 实际结果
<!--
示例：
程序能正常执行，但控制台没有输出`代理方法被调用`
-->



### 受影响的设备
<!-- 
请在列出受影响的设备，并添加对应 iOS 版本。
这里仅需要列出您测试过的设备，并不需要去测试所有的设备。
例如：
- iPhone 8 (11.0.3)
- iPhone 8 Plus (11.0.3, 12.0.1)
-->



### 版本信息
<!-- 
这里除了PYSearch 版本都不是必须的，如果能提供最好，不能提供也没关系
CocoaPods 版本：`pod  --version`
Xcode 版本：菜单栏选择 Xcode 下的 About Xcode 或 执行 `xcodebuild -version`
macOS 版本：从屏幕角落的苹果 () 菜单中选取 “关于本机” 
-->

- PYSearch：vX.X.X
- Xcode：vX.X.X
- macOS：vX.X.X
- CocoaPods：vX.X.X

