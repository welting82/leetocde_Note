/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

// @lc code=start
class Solution {
public:
    string under1000(int num, vector<string> under_20,vector<string> TWOs)
    {
        string res = "";
        if(num < 1000 && num > 0)
        {
            if(num > 99)
            {
                res += (under_20[num/100] + TWOs.back());
                num %= 100;
            }
            if(num != 0)
            {
                if(num < 20) res += under_20[num];
                else
                {
                    res += TWOs[num/10];
                    if(num%10 != 0)
                    {
                        res += under_20[num%10];
                    }
                }
            }
        }
        return res;
    }
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<string> order = {"Billion ","Million ","Thousand ",""};
        vector<int> order_idx = {10,7,4,1};
        vector<string> under_20 = {"Zero ","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ",
                                "Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
        vector<string> TWOs = {"","","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety ","Hundred "};
        vector<int> v_num;
        string res = "";
        int n, str_num = 0,idx;
        vector<int>::iterator it;
    
        while(num > 0)
        {
            v_num.push_back(num % 10);
            num /= 10;
        }
        reverse(v_num.begin(),v_num.end());
        n = v_num.size();

        for(int i = 0; i < v_num.size(); i++)
        {
            str_num = str_num*10 + v_num[i];
            if((it = find(order_idx.begin(),order_idx.end(),(n - i))) != order_idx.end() && str_num > 0)
            {
                idx = distance(order_idx.begin(), it);
                res += (under1000(str_num,under_20,TWOs) + order[idx]);
                str_num = 0;
            }
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end
/*
123\n
2147483647\n
2147483607\n
2147483047\n
2147480647\n
2140483647\n
21483647\n
1111111111\n
1604020704\n
90000004\n
90000004\n
904\n
9004\n
90004\n
900004\n
9000004\n
100\n
1100\n
2000000000\n
200000000\n
20000000\n
2000000\n
200000\n
20000\n
2000\n
200\n
20\n
2\n
*/

