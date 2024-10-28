/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res(queries.size(),0);
        int sum = 0, n = arr.size(), cnt = 0;
        
        for(int i:arr) sum ^= i;

        for(auto i:queries)
        {
            if((i[1] - i[0]) < (n / 2))
            {
                for(int idx = i[0]; idx <= i[1]; idx++) res[cnt] ^= arr[idx];
            }
            else
            {
                res[cnt] = sum;
                for(int idx = 0; idx < i[0]; idx++) res[cnt] ^= arr[idx];
                for(int idx = i[1] + 1; idx < n; idx++) res[cnt] ^= arr[idx];
            }
            cnt++;
        }

        return res;
    }
};
// @lc code=end
/*
[2,7,14,8]\n[1,11,14,10,7]\n
[[0,2],[0,0],[2,3],[1,4]]\n
[[0,1],[1,2],[0,3],[3,3]]\n
[4,8,2,10]\n
[[2,3],[1,3],[0,0],[0,3]]\n
[1,11,14,10,7]\n
[[0,2],[0,0],[2,3],[1,4]]\n
*/
