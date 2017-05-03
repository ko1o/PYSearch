# PYSearch

[![Build Status](https://travis-ci.org/iphone5solo/PYSearch.svg?branch=master)](https://travis-ci.org/iphone5solo/PYSearch)
[![Pod Version](http://img.shields.io/cocoapods/v/PYSearch.svg?style=flat)](http://cocoadocs.org/docsets/PYSearch/)
[![Pod Platform](http://img.shields.io/cocoapods/p/PYSearch.svg?style=flat)](http://cocoadocs.org/docsets/PYSearch/)
[![Pod License](http://img.shields.io/cocoapods/l/PYSearch.svg?style=flat)](https://opensource.org/licenses/MIT)

- 🔍 An elegant search controller for iOS.

## Features
- [x] Support a variety of hot search style
- [x] Support a variety of search history style
- [x] Support a variety of search results display mode
- [x] Support search suggestions
- [x] Support search history (record) cache
- [x] Support callback using delegate or block completion search
- [x] Support CocoaPods
- [x] Support localization
- [x] Support vertical and horizontal screen on iPhone and iPad

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
- `UIColor+PYSearchExtension`
- `UIView+PYSearchExtension`
- `NSBundle+PYSearchExtension`

## Contents
* Getting Started
  * [Renderings](#Renderings)
  * [Styles](#Styles)
  
* Usage
  * [How to use](#Howtouse)
  * [Details (See the example program PYSearchExample for details)](#Details)
  * [Custom](#Custom)
  
* [Hope](#Hope)

## <a id="Renderings"></a>Renderings

<img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/PYSearchDemo.gif" width="375"> 

## <a id="Styles"></a>Styles

#### Hot search style
<img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/hotSearchStyle01.png" width="375"> <img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/hotSearchStyle02.png" width="375"><br><img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/hotSearchStyle03.png" width="375"> <img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/hotSearchStyle04.png" width="375"><br><img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/hotSearchStyle05.png" width="375"> <img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/hotSearchStyle06.png" width="375"> 

#### Search history style
<img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/searchHistoryStyle01.png" width="375"> <img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/searchHistoryStyle02.png" width="375"><br><img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/searchHistoryStyle03.png" width="375"> <img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/searchHistoryStyle04.png" width="375"><br><img src="https://github.com/iphone5solo/learngit/raw/master/imagesForPYSearch/searchHistoryStyle05.png" width="375">

## <a id="How to use"></a>How to use
* Use CocoaPods:
  - `pod "PYSearch"`
  - Import the main file：`#import <PYSearch.h>`
* Manual import：
  - Drag All files in the `PYSearch` folder to project
  - Import the main file：`#import "PYSearch.h"`
  
  
## <a id="Details"></a>Details (See the example program PYSearchExample for details)
```objc
    // 1. Create hotSearches array
    NSArray *hotSeaches = @[@"Java", @"Python", @"Objective-C", @"Swift", @"C", @"C++", @"PHP", @"C#", @"Perl", @"Go", @"JavaScript", @"R", @"Ruby", @"MATLAB"];
    // 2. Create searchViewController
    PYSearchViewController *searchViewController = [PYSearchViewController searchViewControllerWithHotSearches:hotSeaches searchBarPlaceholder:@"Search programming language" didSearchBlock:^(PYSearchViewController *searchViewController, UISearchBar *searchBar, NSString *searchText) {
        // Call this Block when completion search automatically
        // Such as: Push to a view controller
        [searchViewController.navigationController pushViewController:[[UIViewController alloc] init] animated:YES];
        
    }];
    // 3. present the searchViewController
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:searchViewController];
    [self presentViewController:nav  animated:NO completion:nil];

```

## <a id="Custom"></a>Custom

* Custom search suggestions display
```objc
// 1. Set dataSource
searchViewController.dataSource = self;
// 2. Implement dataSource method
```

* Custom search result dispaly
```objc
// 1. Set searchResultShowMode
searchViewController.searchResultShowMode = PYSearchResultShowModeEmbed;
// 2. Set searchResultController 
searchViewController.searchResultController = [[UIViewController alloc] init];
```

* Set hotSearchStyle（default is PYHotSearchStyleNormalTag）
```objc
// Set hotSearchStyle
searchViewController.hotSearchStyle = PYHotSearchStyleColorfulTag;
```

* Set searchHistoryStyle（default is PYSearchHistoryStyleCell）
```objc
// Set searchHistoryStyle
searchViewController.searchHistoryStyle = PYSearchHistoryStyleBorderTag;
```

* Set searchHistoriesCachePath（default is PYSEARCH_SEARCH_HISTORY_CACHE_PATH）
```objc
// Set searchHistoriesCachePath
searchViewController.searchHistoriesCachePath = @"The cache path";
```

* Set searchHistoriesCount（default is 20）
```objc
// Set searchHistoriesCount
searchViewController. searchHistoriesCount = 6;
```

* Set searchResultShowMode（default is PYSearchResultShowModeCustom）
```objc
// Set searchResultShowMode
searchViewController.searchResultShowMode = PYSearchResultShowModeEmbed;
```

* Set searchSuggestionHidden（deafult is NO）
```objc
// Set searchSuggestionHidden
searchViewController.searchSuggestionHidden = YES;
```

## <a id="Hope"></a>Hope

- If you have any questions during the process or want more interfaces to customize，you can [issues me](https://github.com/iphone5solo/PYSearch/issues/new)! 
- Instead of giving me star, it is better to throw a bug to me!
- If you want to participate in the maintenance of this project or have a good design style, welcome to pull request!
- If you feel slightly discomfort in use, please contact me QQ:499491531 or Email:499491531@qq.com.
- Hope to improve this project together, let it become more powerful, able to meet the needs of most users!

## Licenses
All source code is licensed under the MIT License.
