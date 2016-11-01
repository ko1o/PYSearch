// 
//  代码地址: https://github.com/iphone5solo/PYSearch
//  代码地址: http://www.code4app.com/thread-11175-1-1.html
//  Created by CoderKo1o.
//  Copyright © 2016年 iphone5solo. All rights reserved.
//  最主要的搜索控制器

#import <UIKit/UIKit.h>

@class PYSearchViewController;

typedef void(^PYDidSearchBlock)(PYSearchViewController *searchViewController, UISearchBar *searchBar, NSString *searchText); // 开始搜索时调用的block

typedef NS_ENUM(NSInteger, PYHotSearchStyle)  { // 热门搜索标签风格
    PYHotSearchStyleNormalTag,      // 普通标签(不带边框)
    PYHotSearchStyleColorfulTag,    // 彩色标签（不带边框，背景色为随机彩色）
    PYHotSearchStyleBorderTag,      // 带有边框的标签,此时标签背景色为clearColor
    PYHotSearchStyleARCBorderTag,   // 带有圆弧边框的标签,此时标签背景色为clearColor
    PYHotSearchStyleRankTag,        // 带有排名标签
    PYHotSearchStyleRectangleTag,   // 矩形标签,此时标签背景色为clearColor
    PYHotSearchStyleDefault = PYHotSearchStyleNormalTag // 默认为普通标签
};

typedef NS_ENUM(NSInteger, PYSearchHistoryStyle) {  // 搜索历史风格
    PYSearchHistoryStyleCell,           // UITableViewCell 风格
    PYSearchHistoryStyleNormalTag,      // PYHotSearchStyleNormalTag 标签风格
    PYSearchHistoryStyleColorfulTag,    // 彩色标签（不带边框，背景色为随机彩色）
    PYSearchHistoryStyleBorderTag,      // 带有边框的标签,此时标签背景色为clearColor
    PYSearchHistoryStyleARCBorderTag,   // 带有圆弧边框的标签,此时标签背景色为clearColor
    PYSearchHistoryStyleDefault = PYSearchHistoryStyleCell // 默认为 PYSearchHistoryStyleCell
};

typedef NS_ENUM(NSInteger, PYSearchResultShowMode) { // 搜索结果显示方式
    PYSearchResultShowModeCustom,   // 通过自定义显示
    PYSearchResultShowModePush,     // 通过Push控制器显示
    PYSearchResultShowModeEmbed,    // 通过内嵌控制器View显示
    PYSearchResultShowModeDefault = PYSearchResultShowModeCustom // 默认为用户自定义（自己处理）
};

@protocol PYSearchViewControllerDelegate <NSObject, UITableViewDelegate>

@optional
/** 点击(开始)搜索时调用 */
- (void)searchViewController:(PYSearchViewController *)searchViewController didSearchWithsearchBar:(UISearchBar *)searchBar searchText:(NSString *)searchText;
/** 搜索框文本变化时，显示的搜索建议通过searchViewController的searchSuggestions赋值即可 */
- (void)searchViewController:(PYSearchViewController *)searchViewController  searchTextDidChange:(UISearchBar *)seachBar searchText:(NSString *)searchText;
/** 点击取消时调用 */
- (void)didClickCancel:(PYSearchViewController *)searchViewController;

@end

@interface PYSearchViewController : UIViewController

/** 
 * 排名标签背景色对应的16进制字符串（如：@"#ffcc99"）数组(四个颜色)
 * 前三个为分别为1、2、3 第四个为后续所有标签的背景色
 * 该属性只有在设置hotSearchStyle为PYHotSearchStyleColorfulTag才生效
 */
@property (nonatomic, strong) NSArray<NSString *> *rankTagBackgroundColorHexStrings;

/** 
 * web安全色池,存储的是UIColor数组，用于设置标签的背景色
 * 该属性只有在设置hotSearchStyle为PYHotSearchStyleColorfulTag才生效
 */
@property (nonatomic, strong) NSMutableArray<UIColor *> *colorPol;

/** 代理 */
@property (nonatomic, weak) id<PYSearchViewControllerDelegate> delegate;

/** 热门搜索风格 （默认为：PYHotSearchStyleDefault）*/
@property (nonatomic, assign) PYHotSearchStyle hotSearchStyle;
/** 搜索历史风格 （默认为：PYSearchHistoryStyleDefault）*/
@property (nonatomic, assign) PYSearchHistoryStyle searchHistoryStyle;
/** 显示搜索结果模式（默认为自定义：PYSearchResultShowModeDefault） */
@property (nonatomic, assign) PYSearchResultShowMode searchResultShowMode;

/** 搜索时调用此Block */
@property (nonatomic, copy) PYDidSearchBlock didSearchBlock;
/** 搜索建议,注意：给此属性赋值时，确保searchSuggestionHidden值为NO，否则赋值失效 */
@property (nonatomic, copy) NSArray<NSString *> *searchSuggestions;
/** 搜索建议是否隐藏 默认为：NO */
@property (nonatomic, assign) BOOL searchSuggestionHidden;

/** 搜索结果TableView (只有searchResultShowMode != PYSearchResultShowModeCustom才有值) */
@property (nonatomic, weak) UITableView *searchResultTableView;
/** 搜索结果控制器 */
@property (nonatomic, strong) UITableViewController *searchResultController;

/**
 * 快速创建PYSearchViewController对象
 *
 * hotSearches : 热门搜索数组
 * placeholder : searchBar占位文字
 *
 */
+ (PYSearchViewController *)searchViewControllerWithHotSearches:(NSArray<NSString *> *)hotSearches searchBarPlaceholder:(NSString *)placeholder;

/**
 * 快速创建PYSearchViewController对象
 *
 * hotSearches : 热门搜索数组
 * placeholder : searchBar占位文字
 * block: 点击（开始）搜索时调用block
 * 注意 : delegate(代理)的优先级大于block(即实现了代理方法则block失效)
 *
 */
+ (PYSearchViewController *)searchViewControllerWithHotSearches:(NSArray<NSString *> *)hotSearches searchBarPlaceholder:(NSString *)placeholder didSearchBlock:(PYDidSearchBlock)block;
@end
