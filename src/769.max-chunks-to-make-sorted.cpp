/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, sum = 0, ref = 0;

        for(int i = 0; i < arr.size(); i++)
        {
            sum += arr[i], ref += i;
            if(sum == ref) res++;
        }
        return res;
    }
};
// @lc code=end
/*
[4,3,2,1,0]\n
[1,0,2,3,4]\n
[1,0,2,3,4,6,5]\n
[1,2,0,3]\n
[2,0,1]\n
*/
