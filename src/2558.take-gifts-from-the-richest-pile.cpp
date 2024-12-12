/*
 * @lc app=leetcode id=2558 lang=cpp
 *
 * [2558] Take Gifts From the Richest Pile
 */

// @lc code=start
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        int pile;
        long long res = 0;

        for(int i:gifts) pq.push(i);

        while (k--)
        {
            pile = pq.top(), pq.pop();
            pq.push(floor(sqrt(pile)));
        }
        while(!pq.empty())
        {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

