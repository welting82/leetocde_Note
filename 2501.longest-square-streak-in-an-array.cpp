/*
 * @lc app=leetcode id=2501 lang=cpp
 *
 * [2501] Longest Square Streak in an Array
 */

// @lc code=start
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int res = 1;
        long long n;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pair<long long,int> set;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++)
        {
            n = (long long) nums[i] * nums[i];
            while(!pq.empty() && nums[i] > pq.top().first)
            {
                res = max(pq.top().second,res),pq.pop();
            }
            if(!pq.empty() && nums[i] == pq.top().first)
            {
                set = pq.top(),pq.pop();
                set.second++;
                set.first = n;
                pq.push(set);
            }
            else pq.push({n,1});
        }

        while(!pq.empty()) res = max(pq.top().second,res),pq.pop();
        return (res == 1)?-1:res;
    }
};
// @lc code=end
/*
[4,3,6,16,8,2]\n
[4,3,256,6,16,8,2,9,81]\n
[2,3,5,6,7]\n
[4,16,256,65536]\n
[5,12,3,10,4,11,4,16,11]\n
*/
