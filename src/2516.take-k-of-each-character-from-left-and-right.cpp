/*
 * @lc app=leetcode id=2516 lang=cpp
 *
 * [2516] Take K of Each Character From Left and Right
 */

// @lc code=start
class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        vector<int> count(3,0);
        for(int ch:s) count[ch-'a']++;
        int l = 0, r = 0;
        int _max = -1;

        if(count[0] < k || count[1] < k || count[2] < k) return -1;

        for( ; r < s.length(); r++)
        {
            count[s[r]-'a']--;

            // 移動左指標直到合法
            while(l <= r && (count[0]<k || count[1] < k || count[2] <k)) 
            {
                count[s[l++] - 'a']++;
            }
            _max = max(_max, r-l+1);
        }
        // 字串長度減去最大值
        return s.length() - _max;
    }
};
// @lc code=end

