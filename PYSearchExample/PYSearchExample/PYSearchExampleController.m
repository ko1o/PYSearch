//
//  GitHub: https://github.com/iphone5solo/PYSearch
//  Created by CoderKo1o.
//  Copyright © 2016 iphone5solo. All rights reserved.
//

#import "PYSearchExampleController.h"
#import "PYSearch.h"
#import "PYTempViewController.h"

@interface PYSearchExampleController () <PYSearchViewControllerDelegate>

@end

@implementation PYSearchExampleController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // set title
    self.title = @"PYSearch Example";
    self.tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
    if ([self.tableView respondsToSelector:@selector(setCellLayoutMarginsFollowReadableWidth:)]) { // Adjust for iPad
        self.tableView.cellLayoutMarginsFollowReadableWidth = NO;
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 2;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return section ? 5 : 6;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [[UITableViewCell alloc] init];
    if (0 == indexPath.section) {
        cell.textLabel.text = @[@"PYHotSearchStyleDefault", @"PYHotSearchStyleColorfulTag", @"PYHotSearchStyleBorderTag", @"PYHotSearchStyleARCBorderTag", @"PYHotSearchStyleRankTag", @"PYHotSearchStyleRectangleTag"][indexPath.row];
    } else {
        cell.textLabel.text = @[@"PYSearchHistoryStyleDefault", @"PYSearchHistoryStyleNormalTag", @"PYSearchHistoryStyleColorfulTag", @"PYSearchHistoryStyleBorderTag", @"PYSearchHistoryStyleARCBorderTag"][indexPath.row];
    }
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // 1. Create an Array of popular search
    NSArray *hotSeaches = @[@"Java", @"Python", @"Objective-C", @"Swift", @"C", @"C++", @"PHP", @"C#", @"Perl", @"Go", @"JavaScript", @"R", @"Ruby", @"MATLAB"];
    // 2. Create a search view controller
    PYSearchViewController *searchViewController = [PYSearchViewController searchViewControllerWithHotSearches:hotSeaches searchBarPlaceholder:NSLocalizedString(@"PYExampleSearchPlaceholderText", @"搜索编程语言") didSearchBlock:^(PYSearchViewController *searchViewController, UISearchBar *searchBar, NSString *searchText) {
        // Called when search begain.
        // eg：Push to a temp view controller
        [searchViewController.navigationController pushViewController:[[PYTempViewController alloc] init] animated:YES];
    }];
    // 3. Set style for popular search and search history
    if (0 == indexPath.section) {
        searchViewController.hotSearchStyle = (NSInteger)indexPath.row;
        searchViewController.searchHistoryStyle = PYHotSearchStyleDefault;
    } else {
        searchViewController.hotSearchStyle = PYHotSearchStyleDefault;
        searchViewController.searchHistoryStyle = (NSInteger)indexPath.row; 
    }
    // 4. Set delegate
    searchViewController.delegate = self;
    // 5. Present(Modal) or push search view controller
    // Present(Modal)
//    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:searchViewController];
//    [self presentViewController:nav animated:YES completion:nil];
    // Push
    // Set mode of show search view controller, default is `PYSearchViewControllerShowModeModal`
    searchViewController.searchViewControllerShowMode = PYSearchViewControllerShowModePush;
//    // Push search view controller
    [self.navigationController pushViewController:searchViewController animated:YES];
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return section ? NSLocalizedString(@"PYExampleTableSectionZeroTitle", @"选择搜索历史风格（热门搜索为默认风格)") : NSLocalizedString(@"PYExampleTableSectionZeroTitle", @"选择热门搜索风格（搜索历史为默认风格)");
}

#pragma mark - PYSearchViewControllerDelegate
- (void)searchViewController:(PYSearchViewController *)searchViewController searchTextDidChange:(UISearchBar *)seachBar searchText:(NSString *)searchText
{
    if (searchText.length) {
        // Simulate a send request to get a search suggestions
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.25 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            NSMutableArray *searchSuggestionsM = [NSMutableArray array];
            for (int i = 0; i < arc4random_uniform(5) + 10; i++) {
                NSString *searchSuggestion = [NSString stringWithFormat:@"Search suggestion %d", i];
                [searchSuggestionsM addObject:searchSuggestion];
            }
            // Refresh and display the search suggustions
            searchViewController.searchSuggestions = searchSuggestionsM;
        });
    }
}
@end
