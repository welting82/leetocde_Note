/*
 * @lc app=leetcode id=1054 lang=cpp
 *
 * [1054] Distant Barcodes
 */

// @lc code=start
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int,int>> pq;
        int cnt = 0, pre, idx = 0, n = barcodes.size();
        vector<int> res(n);

        sort(barcodes.begin(), barcodes.end());
        pre = barcodes[0];
        for(auto i:barcodes)
        {
            if(i == pre) cnt++;
            else 
            {
                pq.push({cnt, pre});
                pre = i, cnt = 1;
            }
        }
        pq.push({cnt, pre});

        while(!pq.empty())
        {
            cnt = pq.top().first, pre = pq.top().second, pq.pop();
            for(int i = 0; i < cnt; i++)
            {
                if(idx >= n) idx = 1;
                res[idx] = pre, idx += 2;
            }
        }
        return res;
    }
};
// @lc code=end
/*
[1,1,1,1,2,2,3,3]\n
[1,1,1,1,1,1,1,3,4,2,2,3,3]\n
*/
