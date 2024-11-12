/*
 * @lc app=leetcode id=2601 lang=cpp
 *
 * [2601] Prime Subtraction Operation
 */

// @lc code=start
class Solution {
public:
    vector<int> prime = {0,2,3,5,7,11,13,17};
    void findPrime()
    {
        int num = prime.back() + 1, idx = 1;
        while(idx < prime.size())
        {
            if(num % prime[idx] == 0) num++, idx = 1;
            else idx++;
        }
        prime.push_back(num);
        return;
    }

    bool primeSubOperation(vector<int>& nums) {
        int idx;
        for(int i = nums.size() - 2; i > -1; i--)
        {
            idx = 0;
            while(nums[i] - prime[idx]>= nums[i + 1])
            {
                if(idx == prime.size() - 1) findPrime();
                idx++;
            }
            nums[i] -= prime[idx];
            if(nums[i] <= 0) return false;
        }
        return true;
    }
};
// @lc code=end
/*
[6,8,10,10]\n
[4,9,6,10]\n
[6,8,11,12]\n
[5,8,3]\n
[5,543,2,54,654,235,66,63,525,25,254,456,509,567,523,914]\n
[2,2]\n
[18,12,14,6]\n
*/
