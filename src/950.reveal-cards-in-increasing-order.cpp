/*
 * @lc app=leetcode id=950 lang=cpp
 *
 * [950] Reveal Cards In Increasing Order
 */

// @lc code=start
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size(), idx = 0;
        vector<int> res(n,0);
        queue<int> q;

        for(int i = 0; i < n; i++) q.push(i);
        sort(deck.begin(), deck.end());

        while (!q.empty() && idx < n)
        {
            res[q.front()] = deck[idx];
            q.pop();
            q.push(q.front());
            q.pop();
            idx++;
        }
        return res;
    }
};
// @lc code=end

