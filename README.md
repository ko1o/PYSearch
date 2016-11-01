# PYSearch

[![Build Status](https://travis-ci.org/iphone5solo/PYSearch.svg?branch=master)](https://travis-ci.org/iphone5solo/PYSearch)
[![Pod Version](http://img.shields.io/cocoapods/v/PYSearch.svg?style=flat)](http://cocoadocs.org/docsets/PYSearch/)
[![Pod Platform](http://img.shields.io/cocoapods/p/PYSearch.svg?style=flat)](http://cocoadocs.org/docsets/PYSearch/)
[![Pod License](http://img.shields.io/cocoapods/l/PYSearch.svg?style=flat)](https://opensource.org/licenses/MIT)

- 🔍 An elegant search controller for iOS.
- 🔍 iOS 中一款优雅的搜索控制器。

## Features
- [x] 支持多种热门搜索风格
- [x] 支持多种搜索历史风格
- [x] 支持多种搜索结果显示模式
- [x] 支持搜索建议
- [x] 支持搜索历史（记录）缓存
- [x] 支持使用delegate 或者 block 完成搜索时的回调
- [x] 支持CocoaPods

## Requirements
* iOS 7.0 or later
* Xcode 7.0 or later

## Architecture
### Main
- `PYSearch`
- `PYSearchConst`
- `PYSearchViewController`
- `PYSearchSuggestionViewController`

### Category
- `UIColor+PYExtension`
- `UIView+PYExtension`

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

<img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/PYSearchDemo.gif" width="375"> 

## <a id="支持哪些风格"></a>支持哪些风格

#### 热门搜索风格
<img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/hotSearchStyle01.png" width="375"> <img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/hotSearchStyle02.png" width="375"><br><img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/hotSearchStyle03.png" width="375"> <img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/hotSearchStyle04.png" width="375"><br><img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/hotSearchStyle05.png" width="375"> <img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/hotSearchStyle06.png" width="375"> 

#### 搜索历史风格
<img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/searchHistoryStyle01.png" width="375"> <img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/searchHistoryStyle02.png" width="375"><br><img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/searchHistoryStyle03.png" width="375"> <img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/searchHistoryStyle04.png" width="375"><br><img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/searchHistoryStyle05.png" width="375">

## <a id="如何使用PYSearch"></a>如何使用PYSearch
* 使用CocoaPods:
  - `pod "PYSearch"`
  - 导入主头文件`#import <PYSearch.h>`
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

## <a id="自定义PYSearch"></a>自定义PYSearch

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

* 设置搜索结果显示模式（默认为PYSearchResultShowModePush）
```objc
	// 设置搜索模式为内嵌
	searchViewController.searchResultShowMode = PYSearchResultShowModeEmbed;
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
- 如果您在使用中觉得略有不适，欢迎联系我QQ:499491531，希望一起完善此项目，让它变成更强大，能够满足大多数用户的需求！

## Licenses
All source code is licensed under the MIT License.
