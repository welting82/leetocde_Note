/*
 * @lc app=leetcode id=2285 lang=cpp
 *
 * [2285] Maximum Total Importance of Roads
 */

// @lc code=start
class Solution {
public:

    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long res = 0;
        vector<pair<int,int>> vec(n,{-1,0});
        unordered_map<int,int> umap;
        for(auto i:roads)
        {
            vec[i[0]].first = i[0];
            vec[i[0]].second++;
            vec[i[1]].first = i[1];
            vec[i[1]].second++;
        }
        sort(vec.begin(),vec.end(),[](const auto &a, const auto &b)
        {
            return a.second > b.second;
        }
        );
        for(auto i:vec) umap[i.first] = n--;
        for(auto i:roads)
        {
            res += (umap[i[0]] + umap[i[1]]);
        }

        return res;
    }
};
// @lc code=end
/*
5\n
[[0,1]]\n
*/
