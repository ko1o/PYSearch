//
//  GitHub: https://github.com/iphone5solo/PYSearch
//  Created by CoderKo1o.
//  Copyright © 2016 iphone5solo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PYSearchConst.h"

@class PYSearchViewController, PYSearchSuggestionViewController;

typedef void(^PYDidSearchBlock)(PYSearchViewController *searchViewController, UISearchBar *searchBar, NSString *searchText);

/**
 style of popular search
 */
typedef NS_ENUM(NSInteger, PYHotSearchStyle)  {
    PYHotSearchStyleNormalTag,      // normal tag without border
    PYHotSearchStyleColorfulTag,    // colorful tag without border, color of background is randrom and can be custom by `colorPol`
    PYHotSearchStyleBorderTag,      // border tag, color of background is `clearColor`
    PYHotSearchStyleARCBorderTag,   // broder tag with ARC, color of background is `clearColor`
    PYHotSearchStyleRankTag,        // rank tag, color of background can be custom by `rankTagBackgroundColorHexStrings`
    PYHotSearchStyleRectangleTag,   // rectangle tag, color of background is `clearColor`
    PYHotSearchStyleDefault = PYHotSearchStyleNormalTag // default is `PYHotSearchStyleNormalTag`
};

/**
 style of search history
 */
typedef NS_ENUM(NSInteger, PYSearchHistoryStyle) {
    PYSearchHistoryStyleCell,           // style of UITableViewCell
    PYSearchHistoryStyleNormalTag,      // style of PYHotSearchStyleNormalTag
    PYSearchHistoryStyleColorfulTag,    // style of PYHotSearchStyleColorfulTag
    PYSearchHistoryStyleBorderTag,      // style of PYHotSearchStyleBorderTag
    PYSearchHistoryStyleARCBorderTag,   // style of PYHotSearchStyleARCBorderTag
    PYSearchHistoryStyleDefault = PYSearchHistoryStyleCell // default is `PYSearchHistoryStyleCell`
};

/**
 mode of search result view controller display
 */
typedef NS_ENUM(NSInteger, PYSearchResultShowMode) {
    PYSearchResultShowModeCustom,   // custom, can be push or pop and so on.
    PYSearchResultShowModePush,     // push, dispaly the view of search result by push
    PYSearchResultShowModeEmbed,    // embed, dispaly the view of search result by embed
    PYSearchResultShowModeDefault = PYSearchResultShowModeCustom // defualt is `PYSearchResultShowModeCustom`
};

/**
 The protocol of data source, you can custom the suggestion view by implement these methods the data scource.
 */
@protocol PYSearchViewControllerDataSource <NSObject>

@optional

/**
 Return a `UITableViewCell` object.

 @param searchSuggestionView    view which display search suggestions
 @param indexPath               indexPath of row
 @return a `UITableViewCell` object
 */
- (UITableViewCell *)searchSuggestionView:(UITableView *)searchSuggestionView cellForRowAtIndexPath:(NSIndexPath *)indexPath;

/**
 Return number of rows in section.

 @param searchSuggestionView    view which display search suggestions
 @param section                 index of section
 @return number of rows in section
 */
- (NSInteger)searchSuggestionView:(UITableView *)searchSuggestionView numberOfRowsInSection:(NSInteger)section;

/**
 Return number of sections in search suggestion view.

 @param searchSuggestionView    view which display search suggestions
 @return number of sections
 */
- (NSInteger)numberOfSectionsInSearchSuggestionView:(UITableView *)searchSuggestionView;

/**
 Return height for row.

 @param searchSuggestionView    view which display search suggestions
 @param indexPath               indexPath of row
 @return height of row
 */
- (CGFloat)searchSuggestionView:(UITableView *)searchSuggestionView heightForRowAtIndexPath:(NSIndexPath *)indexPath;

@end


/**
 The protocol of delegate
 */
@protocol PYSearchViewControllerDelegate <NSObject, UITableViewDelegate>

@optional

/**
 Called when search begain.

 @param searchViewController    search view controller
 @param searchBar               search bar
 @param searchText              text for search
 */
- (void)searchViewController:(PYSearchViewController *)searchViewController
      didSearchWithSearchBar:(UISearchBar *)searchBar
                  searchText:(NSString *)searchText;

/**
 Called when popular search is selected.

 @param searchViewController    search view controller
 @param index                   index of tag
 @param searchText              text for search
 
 Note: `searchViewController:didSearchWithSearchBar:searchText:` will not be called when this method is implemented.
 */
- (void)searchViewController:(PYSearchViewController *)searchViewController
   didSelectHotSearchAtIndex:(NSInteger)index
                  searchText:(NSString *)searchText;

/**
 Called when search history is selected.

 @param searchViewController    search view controller
 @param index                   index of tag or row
 @param searchText              text for search
 
 Note: `searchViewController:didSearchWithSearchBar:searchText:` will not be called when this method is implemented.
 */
- (void)searchViewController:(PYSearchViewController *)searchViewController
didSelectSearchHistoryAtIndex:(NSInteger)index
                  searchText:(NSString *)searchText;

/**
 Called when search suggestion is selected.

 @param searchViewController    search view controller
 @param index                   index of row
 @param searchText              text for search

 Note: `searchViewController:didSearchWithSearchBar:searchText:` will not be called when this method is implemented.
 */
- (void)searchViewController:(PYSearchViewController *)searchViewController
didSelectSearchSuggestionAtIndex:(NSInteger)index
                  searchText:(NSString *)searchText PYSEARCH_DEPRECATED("Use searchViewController:didSelectSearchSuggestionAtIndexPath:searchText:");

/**
 Called when search suggestion is selected, the method support more custom of search suggestion view.

 @param searchViewController    search view controller
 @param indexPath               indexPath of row
 @param searchBar               search bar
 
 Note: `searchViewController:didSearchWithSearchBar:searchText:` and `searchViewController:didSelectSearchSuggestionAtIndex:searchText:` will not be called when this method is implemented.
 Suggestion: To ensure that can cache selected custom search suggestion records, you need to set `searchBar.text` = "custom search text".
 */
- (void)searchViewController:(PYSearchViewController *)searchViewController didSelectSearchSuggestionAtIndexPath:(NSIndexPath *)indexPath
                   searchBar:(UISearchBar *)searchBar;

/**
 Called when search text did change, you can reload data of suggestion view thought this method.

 @param searchViewController    search view controller
 @param searchBar               search bar
 @param searchText              text for search
 */
- (void)searchViewController:(PYSearchViewController *)searchViewController
         searchTextDidChange:(UISearchBar *)searchBar
                  searchText:(NSString *)searchText;

/**
 Called when cancel item did press, default execute `[self dismissViewControllerAnimated:YES completion:nil]`.

 @param searchViewController search view controller
 */
- (void)didClickCancel:(PYSearchViewController *)searchViewController;

@end

@interface PYSearchViewController : UIViewController

/**
 The delegate
 */
@property (nonatomic, weak) id<PYSearchViewControllerDelegate> delegate;

/**
 The data source
 */
@property (nonatomic, weak) id<PYSearchViewControllerDataSource> dataSource;

/**
 Ranking the background color of the corresponding hexadecimal string (eg: @"#ffcc99") array (just four colors) when `hotSearchStyle` is `PYHotSearchStyleRankTag`.
 */
@property (nonatomic, strong) NSArray<NSString *> *rankTagBackgroundColorHexStrings;

/**
 The pool of color which are use in colorful tag when `hotSearchStyle` is `PYHotSearchStyleColorfulTag`.
 */
@property (nonatomic, strong) NSMutableArray<UIColor *> *colorPol;

/**
 Whether swap the popular search and search history location, default is NO.
 
 Note: It is‘t effective when `searchHistoryStyle` is `PYSearchHistoryStyleCell`.
 */
@property (nonatomic, assign) BOOL swapHotSeachWithSearchHistory;

/**
 The element of popular search
 */
@property (nonatomic, copy) NSArray<NSString *> *hotSearches;

/**
 The tags of popular search
 */
@property (nonatomic, copy) NSArray<UILabel *> *hotSearchTags;

/**
 The label of popular search header
 */
@property (nonatomic, weak) UILabel *hotSearchHeader;

/**
 Whether show popular search, default is YES.
 */
@property (nonatomic, assign) BOOL showHotSearch;

/**
 The title of popular search
 */
@property (nonatomic, copy) NSString *hotSearchTitle;

/**
 The tags of search history
 */
@property (nonatomic, copy) NSArray<UILabel *> *searchHistoryTags;

/**
 The label of search history header
 */
@property (nonatomic, weak) UILabel *searchHistoryHeader;

/**
 The title of search history
 */
@property (nonatomic, copy) NSString *searchHistoryTitle;

/**
 Whether show search history, default is YES.
 
 Note: search record is not cache when it is NO.
 */
@property (nonatomic, assign) BOOL showSearchHistory;

/**
 The path of cache search record, default is `PYSEARCH_SEARCH_HISTORY_CACHE_PATH`.
 */
@property (nonatomic, copy) NSString *searchHistoriesCachePath;

/**
 The number of cache search record, default is 20.
 */
@property (nonatomic, assign) NSUInteger searchHistoriesCount;

/**
 Whether remove the space of search string, default is YES.
 */
@property (nonatomic, assign) BOOL removeSpaceOnSearchString;

/**
 The button of empty search record when `searchHistoryStyle` is’t `PYSearchHistoryStyleCell`.
 */
@property (nonatomic, weak) UIButton *emptyButton;

/**
 The label od empty search record when `searchHistoryStyle` is `PYSearchHistoryStyleCell`.
 */
@property (nonatomic, weak) UILabel *emptySearchHistoryLabel;

/**
 The style of popular search, default is `PYHotSearchStyleNormalTag`.
 */
@property (nonatomic, assign) PYHotSearchStyle hotSearchStyle;

/**
 The style of search histrory, default is `PYSearchHistoryStyleCell`.
 */
@property (nonatomic, assign) PYSearchHistoryStyle searchHistoryStyle;

/**
 The mode of display search result view controller, default is `PYSearchResultShowModeCustom`.
 */
@property (nonatomic, assign) PYSearchResultShowMode searchResultShowMode;

/**
 The search bar
 */
@property (nonatomic, weak) UISearchBar *searchBar;

/**
 The background color of search bar.
 */
@property (nonatomic, strong) UIColor *searchBarBackgroundColor;

/**
 The barButtonItem of cancel
 */
@property (nonatomic, weak) UIBarButtonItem *cancelButton;

/**
 The search suggestion view
 */
@property (nonatomic, weak, readonly) UITableView *searchSuggestionView;

/**
 The block which invoked when search begain.
 */
@property (nonatomic, copy) PYDidSearchBlock didSearchBlock;

/**
 The element of search suggestions
 
 Note: it is't effective when `searchSuggestionHidden` is NO or cell of suggestion view is custom.
 */
@property (nonatomic, copy) NSArray<NSString *> *searchSuggestions;

/**
 Whether hidden search suggstion view, default is NO.
 */
@property (nonatomic, assign) BOOL searchSuggestionHidden;

/**
 The view controller of search result.
 */
@property (nonatomic, strong) UIViewController *searchResultController;

/**
 Whether show search result view when search text did change, default is NO.
 
 Note: it is effective only when `searchResultShowMode` is `PYSearchResultShowModeEmbed`.
 */
@property (nonatomic, assign) BOOL showSearchResultWhenSearchTextChanged;

/**
 Whether show search result view when search bar become first responder again.
 
 Note: it is effective only when `searchResultShowMode` is `PYSearchResultShowModeEmbed`.
 */
@property (nonatomic, assign) BOOL showSearchResultWhenSearchBarRefocused;

/**
 Creates an instance of searchViewContoller with popular searches and search bar's placeholder.

 @param hotSearches     popular searchs
 @param placeholder     placeholder of search bar
 @return new instance of `PYSearchViewController` class
 */
+ (instancetype)searchViewControllerWithHotSearches:(NSArray<NSString *> *)hotSearches
                               searchBarPlaceholder:(NSString *)placeholder;

/**
 Creates an instance of searchViewContoller with popular searches, search bar's placeholder and the block which invoked when search begain.

 @param hotSearches     popular searchs
 @param placeholder     placeholder of search bar
 @param block           block which invoked when search begain
 @return new instance of `PYSearchViewController` class
 
 Note: The `delegate` has a priority greater than the `block`, `block` is't effective when `searchViewController:didSearchWithSearchBar:searchText:` is implemented.
 */
+ (instancetype)searchViewControllerWithHotSearches:(NSArray<NSString *> *)hotSearches
                               searchBarPlaceholder:(NSString *)placeholder
                                     didSearchBlock:(PYDidSearchBlock)block;

@end
