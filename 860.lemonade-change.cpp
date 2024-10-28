/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int coin5 = 0, coin10 = 0, coin20 = 0;

        for(int i:bills)
        {
            switch (i)
            {
                case 5:
                    coin5++;
                    break;
                
                case 10:
                    if(coin5 < 1) return false;
                    coin10++, coin5--;
                    break;

                case 20:
                    if((coin10 < 1 || coin5 < 1) && coin5 < 3) return false;
                    coin20++;
                    if(coin10 > 0) coin10--, coin5--;
                    else coin5 -= 3;
                    break;

                default:
                    break;
            }
        }
        return true;
    }
};
// @lc code=end
/*
[5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5]\n
[5,5,10,10,20]\n
[5,5,5,5,5,5,5,20,5,5,10,10,20,5,5,20,20,10]\n
*/
