/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string v1, string v2) {
        long long v1_num = 0,v2_num = 0;
        int idx1 = 0, idx2 = 0;
        while (idx1 < v1.size() || idx2 < v2.size())
        {
            while (idx1 < v1.size() && v1[idx1] != '.')
            {
                v1_num += (v1_num*10 + v1[idx1] - '0');
                idx1++;
            }
            while (idx2 < v2.size() && v2[idx2] != '.')
            {
                v2_num += (v2_num*10 + v2[idx2] - '0');
                idx2++;
            }
            if(v1_num > v2_num) return 1;
            else if(v1_num < v2_num) return -1;
            else
            {
                v1_num = 0, v2_num = 0;
                idx1++,idx2++;
            }
        }
        return 0;
    }
};
// @lc code=end
/*
"1.01"\n
"1.001"\n
"1.0"\n
"1.0.0"\n
"0.1"\n
"1.1"\n
"1.0.1"\n
"1"\n
"1.2147483647"\n
"1.2147483647"\n
*/
