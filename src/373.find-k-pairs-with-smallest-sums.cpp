/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
            pq.push({nums1[i]+nums2[0],{i,0}});
        while(!pq.empty() && k--)
        {
            pair<int,pair<int,int>> tp = pq.top();
            int x = tp.second.first, y = tp.second.second;
            pq.pop();
            ans.push_back({nums1[x], nums2[y]});
            if(y != m-1)
                pq.push({nums1[x]+nums2[y+1],{x, y+1}});
        }
        return ans;
    }
};
// @lc code=end
/*
[1,7,11]\n
[2,4,6]\n
9\n
[1,1,2]\n
[1,2,3]\n
9\n
[1,2,3]\n
[2,3,5]\n
9\n
*/