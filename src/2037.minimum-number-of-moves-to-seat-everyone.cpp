/*
 * @lc app=leetcode id=2037 lang=cpp
 *
 * [2037] Minimum Number of Moves to Seat Everyone
 */

// @lc code=start
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int res = 0;
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        for(int i = 0; i < seats.size(); i++)
        {
            res += abs(students[i] - seats[i]);
        }
        return res;
    }
};
// @lc code=end

