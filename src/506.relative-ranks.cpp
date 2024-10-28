/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b)
    {
        return (a.first > b.first)?true:false;
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int,int>> rank;
        vector<string> res(n,"");
        for(int i = 0; i < n; i++)
        {
            rank.push_back({score[i],i});
        }
        sort(rank.begin(), rank.end(),cmp);

        for(int j = 0; j < n; j++)
        {
            if(j == 0) res[rank[j].second] = "Gold Medal";
            else if(j == 1) res[rank[j].second] = "Silver Medal";
            else if(j == 2) res[rank[j].second] = "Bronze Medal";
            else res[rank[j].second] = to_string(j+1);
        }
        return res;
    }
};
// @lc code=end
/*
[5,4,3,2,1]\n
[10,3,8,9,4]\n
[123123,11921,1,0,123]\n
*/
