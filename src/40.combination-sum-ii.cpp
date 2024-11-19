/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void helper(int idx, vector<int>& cand, int tgt, vector<int> vec)
    {
        if(tgt == 0) res.push_back(vec);
        else if(tgt > 0)
        {
            for(int i = idx; i < cand.size(); i++)
            {
                if(i != idx && cand[i] == cand[i - 1]) continue;
                vec.push_back(cand[i]);
                helper(i + 1,cand,tgt - cand[i],vec);
                vec.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& cand, int tgt) {
        sort(cand.begin(), cand.end());
        helper(0,cand,tgt,{});
        return res;
    }
};
// @lc code=end
/*
[10,1,2,7,6,1,5,10,10,10]\n
20\n
[2,5,2,1,2]\n
5\n
*/