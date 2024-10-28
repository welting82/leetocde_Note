/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        double res = 0.0, tmp;
        int idx;
        vector<vector<double>> tbl(n, vector<double> (n,0.0));
        
        for(int i = 0; i < edges.size(); i++)
        {
            tbl[edges[i][0]][edges[i][1]] = succProb[i];
            tbl[edges[i][1]][edges[i][0]] = succProb[i];
        }

        for(int i = 0; i < n; i++)
        {
            if(i == start_node) continue;
            tmp = 0.0, idx = end_node;
            
        }

        return res;
    }
};
// @lc code=end

