# PYSearch
- 🔍 An elegant search controller for iOS.
- 🔍 iOS 中一款优雅的搜索控制器。

## Requirements
* iOS 7.0 or later
* Xcode 7.3 or later

## Contents

* Getting Started
  * [Renderings【效果图】](#效果图)
  * [Styles 【支持哪些风格】](#支持哪些风格)
  
* Usage
  * [How to use【如何使用PYSearch】](#如何使用PYSearch)
  * [Details 【具体使用(详情见示例程序PYSearchExample)】](#具体使用（详情见示例程序PYSearchExample）)
  * [Custom【自定义PYSearch】](#自定义PYSearch)
  
* [期待](#期待)

## <a id="效果图"></a>效果图

## <a id="支持哪些风格"></a>支持哪些风格

#### 热门搜索
[img](http://oe1ml9cxe.bkt.clouddn.com/PYHotSearchStyleDefault.png)
[img](http://oe1ml9cxe.bkt.clouddn.com/PYHotSearchStyleColorfulTag.png)
[img](http://oe1ml9cxe.bkt.clouddn.com/PYHotSearchStyleBorderTag.png)
[img](http://oe1ml9cxe.bkt.clouddn.com/PYHotSearchStyleBorderTag.png)
[img](http://oe1ml9cxe.bkt.clouddn.com/PYHotSearchStyleARCBorderTag.png)

[img](http://oe1ml9cxe.bkt.clouddn.com/PYHotSearchStyleColorfulTag.png)
[img](http://oe1ml9cxe.bkt.clouddn.com/PYHotSearchStyleRectangleTag.png)

#### 搜索历史
[img](http://oe1ml9cxe.bkt.clouddn.com/PYSearchHistoryDefault.png)
[img](http://oe1ml9cxe.bkt.clouddn.com/PYSearchHistoryDefault.png)
[img](http://oe1ml9cxe.bkt.clouddn.com/PYSearchHistoryColorfulTag.png)
[img](http://oe1ml9cxe.bkt.clouddn.com/PYSearchHistoryBorderTag.png)
[img](http://oe1ml9cxe.bkt.clouddn.com/PYSearchHistoryBorderTag.png)
[img](http://oe1ml9cxe.bkt.clouddn.com/PYSearchHistoryARCBorderTag.png)

## <a id="如何使用PYSearch"></a>如何使用PYSearch
* 手动导入：
  - 将`PYSearch`文件夹中的所有文件拽入项目中
  - 导入主头文件`#import "PYSearch.h"`
  
  
## <a id="具体使用（详情见示例程序PYSearchExample）"></a>具体使用（详情见示例程序PYSearchExample）
```objc
    // 1. 创建热门搜索数组
    NSArray *hotSeaches = @[@"Java", @"Python", @"Objective-C", @"Swift", @"C", @"C++", @"PHP", @"C#", @"Perl", @"Go", @"JavaScript", @"R", @"Ruby", @"MATLAB"];
    // 2. 创建搜索控制器
    PYSearchViewController *searchViewController = [PYSearchViewController searchViewControllerWithHotSearches:hotSeaches searchBarPlaceholder:@"搜索编程语言" didSearchBlock:^(PYSearchViewController *searchViewController, UISearchBar *searchBar, NSString *searchText) {
        // 开始(点击)搜索时执行以下代码
        // 如：跳转到指定控制器
        [searchViewController.navigationController pushViewController:[[UIViewController alloc] init] animated:YES];
    }];
    // 3. 跳转到搜索控制器
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:searchViewController];
    [self presentViewController:nav  animated:NO completion:nil];

```

## <a id="自定义searchViewContoller"></a>自定义searchViewContoller

### 通过设置searchViewContoller的对象属性值即可修改

* 设置热门搜索风格（默认为PYHotSearchStyleNormalTag）
```objc
	// 设置热门搜索为彩色标签风格
	searchViewController.hotSearchStyle = PYHotSearchStyleColorfulTag;
```

* 设置搜索历史风格（默认为PYSearchHistoryStyleCell）
```objc
	// 设置搜索历史为带边框标签风格
	searchViewController.searchHistoryStyle = PYSearchHistoryStyleBorderTag;
```

* 隐藏搜索建议（默认为：NO）
```objc
	// 隐藏搜索建议
	searchViewController.searchSuggestionHidden = YES;
```

## <a id="期待"></a>期待

- 如果您在使用过程中有任何问题，欢迎issue me! 很乐意为您解答任何相关问题!
- 与其给我点star，不如向我狠狠地抛来一个BUG！
- 如果想要参与这个项目的维护或者有好的设计风格，欢迎pull request！
- 如果您想要更多的接口来自定义或者建议/意见，欢迎issue me！我会根据大家的需求提供更多的接口！

## Licenses
All source code is licensed under the MIT License.