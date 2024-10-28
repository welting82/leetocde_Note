/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& ht) {
        int l = 0, r = ht.size()-1, sum = 0;
        
        while (l < r)
        {
            sum = max(sum,((r - l) * min(ht[r],ht[l])));
            if(ht[l] < ht[r]) l++;
            else if(ht[l] >= ht[r]) r--;
        }
        return sum;
    }
};
// @lc code=end
/*
[1,8,6,2,5,4,8,3,7]\n
[1,8,6,2,5,4,8,3,10,7]\n
[1,1]\n
*/
