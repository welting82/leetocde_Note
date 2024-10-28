/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grumpy, int min) {
        int add = 0, tmp_add = 0, sum = 0;

        for(int i = 0; i < cust.size(); i++)
        {
            sum += (grumpy[i] == 0)?cust[i]:0;
            if(i < min) tmp_add += (grumpy[i] == 1)?cust[i]:0;
            else
            {
                tmp_add += (grumpy[i] == 1)?cust[i]:0;
                tmp_add -= (grumpy[i-min] == 1)?cust[i-min]:0;
            }
            add = max(add,tmp_add);
        }
        return add + sum;
    }
};
// @lc code=end
/*
[1,0,1,2,1,1,7,5]\n
[0,1,0,1,0,1,0,1]\n
3\n

[10,1,7]\n
[0,0,0]\n
2\n

[1]\n
[0]\n
1\n
*/
