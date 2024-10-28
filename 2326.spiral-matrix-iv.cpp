/*
 * @lc app=leetcode id=2326 lang=cpp
 *
 * [2326] Spiral Matrix IV
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m,vector<int> (n,-1));
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        pair<int,int> idx = {0,0};
        int cnt = 0, idx_dir = 0;
        m--,n--;

        while(head)
        {
            res[idx.first][idx.second] = head->val;
            if(idx.first == cnt && idx.second == (n - cnt) && idx_dir == 0) idx_dir++;
            else if(idx.first == (m - cnt) && idx.second == (n - cnt) && idx_dir == 1) idx_dir++;
            else if(idx.first == (m - cnt) && idx.second == cnt && idx_dir == 2) idx_dir++;
            else if(idx.first == (cnt + 1) && idx.second == cnt && idx_dir == 3) idx_dir++,cnt++;
            idx_dir %= 4;
            idx.first += dir[idx_dir].first;
            idx.second += dir[idx_dir].second;
            head = head->next;
        }
        return res;
    }
};
// @lc code=end
/*
3\n
5\n
[3,0,2,6,8,1,7,9,4,2,5,5,0]\n
6\n
4\n
[3,0,2,6,8,1,7,9,4,2,5,5,0,5,6,7,8,9,0,1,2,3,4,5]\n
5\n
5\n
[10,3,0,2,6,8,1,7,9,4,2,5,5,0,5,6,7,8,9,0,1,2,3,4,5]\n
1\n
4\n
[0,1,2]\n
4\n
1\n
[0,1,2]\n
4\n
4\n
[0,1,2]\n
*/
