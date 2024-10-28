/*
 * @lc app=leetcode id=2418 lang=cpp
 *
 * [2418] Sort the People
 */

// @lc code=start
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& h) {
        vector<pair<int,string>> tbl;
        vector<string> res;

        for(int i = 0; i < names.size(); i++)
        {
            tbl.push_back({h[i],names[i]});
        }

        sort(tbl.begin(),tbl.end(),greater());

        for(auto i:tbl)
        {
            res.push_back(i.second);
        }

        return res;
    }
};
// @lc code=end

