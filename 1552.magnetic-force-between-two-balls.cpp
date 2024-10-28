/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 */

// @lc code=start
class Solution {
public:
    bool helper(vector<int> pos, int force, int m) {
        sort(pos.begin(),pos.end());
        int cnt = 1, curr = pos[0];
        for(int i = 1; i < pos.size(); i++)
        {
            if(cnt == m) return true;
            if(curr+force <= pos[i]) curr = pos[i], cnt++;
        }
        return cnt >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        int res = 0, l = 0, r = *max_element(position.begin(), position.end());
        int mid;

        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if(helper(position,mid,m)) l = mid + 1, res = mid;
            else r = mid - 1;
        }
        
        return res;
    }
};
// @lc code=end
/*
[1,2,3,4,7]\n
3\n
[5,4,3,2,1,1000000000]\n
2\n
*/
