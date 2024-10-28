/*
 * @lc app=leetcode id=2053 lang=cpp
 *
 * [2053] Kth Distinct String in an Array
 */

// @lc code=start
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> umap;
        int idx = 0;
        for(string str:arr) umap[str]++;

        while(idx < arr.size())
        {
            if(umap[arr[idx]] < 2) if(--k == 0) return arr[idx];
            idx++;
        }
        return "";
    }
};
// @lc code=end
/*
["d","b","c","b","c","a"]\n
2\n
["aaa","aa","a"]\n
1\n
["a","b","a"]\n
3\n
*/
