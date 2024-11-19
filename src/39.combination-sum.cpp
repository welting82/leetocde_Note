/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void helper(int idx, vector<int>& cand, int tgt, vector<int> vec)
    {
        if(idx == cand.size())
        {
            if(tgt == 0) res.push_back(vec);
        }
        else
        {
            if(cand[idx] <= tgt)
            {
                vec.push_back(cand[idx]);
                helper(idx, cand, tgt - cand[idx], vec);
                vec.pop_back();
            }
            helper(idx + 1, cand, tgt, vec);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& cand, int tgt) {
        sort(cand.begin(), cand.end());
        helper(0,cand,tgt,{});
        return res;
    }
};
// @lc code=end
/*
[2,3,6,7]\n
7\n
[2,3,5]\n
8\n
[2]\n
1\n
*/
