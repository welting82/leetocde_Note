/*
 * @lc app=leetcode id=1105 lang=cpp
 *
 * [1105] Filling Bookcase Shelves
 */

// @lc code=start
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int width = books[i - 1][0], height = books[i - 1][1];
            dp[i] = dp[i - 1] + height;
            for (int j = i - 2; j >= 0 && width + books[j][0] <= shelf_width; --j) {
                height = max(height, books[j][1]);
                width += books[j][0];
                dp[i] = min(dp[i], dp[j] + height);
            }
            
        }
        return dp[n];
    }
};
// @lc code=end
/*
[[1,1],[2,3]]\n
4\n
*/