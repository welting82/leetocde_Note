/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> umap;
        vector<int> res(k,0);
        for(int i:nums) umap[i]++;
        for(auto i:umap) pq.push({i.second,i.first});
        for(int i = 0; i < k; i++) res[i] = pq.top().second,pq.pop();
        return res;
    }
};
// @lc code=end
/*
[1,1,1,2,2,3,3,3,3,3,4]\n
2\n
*/
