/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> freq(128,{' ',0});
        string res;
        for(int ch:s)
        {
            if(freq[ch].first == ' ') freq[ch].first = ch;
            freq[ch].second++;
        }

        sort(freq.begin(), freq.end(), [](auto a, auto b)
        {
            return a.second > b.second;
        });

        for(auto i:freq)
        {
            if(!i.second) break;
            for(int j = 0; j < i.second; j++) res += i.first;
        }
        return res;
    }
};
// @lc code=end
/*
"cccaaa"\n
"Aabb"\n
"cccaaa"\n
"loveleetcode"\n
"BHIUDDDDAAAJJJCCUUassssjssjsddkafkwenccnie83289239du2393"\n
*/
