/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices.size(), 0);
        int idx;
        for(int i = 0; i < prices.size(); i++)
        {
            idx = i + 1;
            while(idx < prices.size() && prices[idx] > prices[i]) idx++;
            res[i] = (idx < prices.size())?(prices[i] - prices[idx]): prices[i];
        }

        return res;
    }
};
// @lc code=end

