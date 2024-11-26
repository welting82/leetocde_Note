/*
 * @lc app=leetcode id=2924 lang=cpp
 *
 * [2924] Find Champion II
 */

// @lc code=start
class Solution {
public:
    vector<int> tbl;
    vector<bool> vis;
    int win(int x)
    {
        if(x == -1 || vis[x]) return -1;
        if(tbl[x] == x) return x;
        return tbl[x] = win(tbl[x]);
    }

    int findChampion(int n, vector<vector<int>>& edges) {
        if(n == 1) return 0;
        int res;
        tbl.resize(n,-1), vis.resize(n,false);
        for(auto i:edges)
        {
            tbl[i[1]] = i[0];
            if(tbl[i[0]] == -1) tbl[i[0]] = i[0];
        }

        res = win(0);
        for(int i = 1; i < n; i++)
        {
            if(win(i) != res) return -1;
            fill(vis.begin(),vis.end(),false);
        }
        
        return res;
    }
};
// @lc code=end
/*
1\n
[]\n
2\n
[]\n
*/
