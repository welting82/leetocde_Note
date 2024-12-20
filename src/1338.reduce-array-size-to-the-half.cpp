/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 */

// @lc code=start
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>> pq;
        int res = 0, pre, cnt = 0, n = arr.size();
        sort(arr.begin(), arr.end());

        pre = arr[0];
        for(int i:arr)
        {
            if(i != pre)
            {
                pq.push({cnt, pre});
                cnt = 1, pre = i;
            }
            else cnt++;
        }
        pq.push({cnt, pre});
        cnt = n;
        while(cnt > n / 2)
        {
            cnt -= pq.top().first, pq.pop();
            res++;
        }

        return res;
    }
};
// @lc code=end
/*
[3,3,3,3,5,5,5,2,2,7]\n
[7,7,7,7,7,7]\n
[3,3,3,3,5,5,5,2,2,3,5,342,123,4,1,2312,234,4,234,12,34,124,12,1,1,1,1,1,1,1,1,100,1,1,1,11]
*/
