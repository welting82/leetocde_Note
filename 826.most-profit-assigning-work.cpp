/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pair<int,int> tmp = {0,0};
        int res = 0, max_profit = 0;
        for(int i = 0; i < diff.size(); i++) pq.push({diff[i],profit[i]});
        sort(worker.begin(),worker.end());

        for(int i:worker)
        {
            while(!pq.empty() && i >= pq.top().first)
            {
                tmp = pq.top(), pq.pop();
                max_profit = max(max_profit, tmp.second);
            }
            res += max_profit;
        }
        return res;
    }
};
// @lc code=end
/*
[2,4,6,8,10]\n
[10,20,30,40,50]\n
[4,5,6,7,11]\n

[20,40,60,108,13]\n
[10,20,30,40,50]\n
[1,5,6,7,11]\n

[68,35,52,47,86]\n
[67,17,1,81,3]\n
[92,10,85,84,82]\n
*/
