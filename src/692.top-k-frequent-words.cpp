/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Compare
{
public:
    bool operator() (auto a, auto b)
    {
        if(a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res, tmp;
        unordered_map<string,int> umap;
        priority_queue<pair<int,string>, vector<pair<int,string>>, Compare> pq;

        for(auto str:words) umap[str]++;
        for(auto i:umap) pq.push({i.second, i.first});

        while(res.size() < k) res.push_back(pq.top().second), pq.pop();
        return res;
    }
};
// @lc code=end
/*
["the","day","is","sunny","the","the","the","sunny","is","is"]\n
4\n
["i","love","leetcode","i","love","coding"]\n
2\n
["i","love","leetcode","i","love","coding"]\n
1\n
*/
