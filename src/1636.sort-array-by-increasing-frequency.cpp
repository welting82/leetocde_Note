/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map <int,int> umap;

        for(int i:nums) umap[i]++;

        sort(nums.begin(),nums.end(), [&umap](int a, int b)
        {
            if(umap[a] > umap[b])return false;
            else if(umap[a] < umap[b])return true;
            else return a > b;
        }
        );

        return nums;
    }
};
// @lc code=end
/*
[1,1,2,2,2,3]\n
[2,3,1,3,2]\n
[-1,1,-6,4,5,-6,1,4,1]\n
*/
