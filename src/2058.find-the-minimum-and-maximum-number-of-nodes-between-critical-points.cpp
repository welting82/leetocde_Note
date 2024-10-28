/*
 * @lc app=leetcode id=2058 lang=cpp
 *
 * [2058] Find the Minimum and Maximum Number of Nodes Between Critical Points
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res(2,-1);
        vector<int> ptr;
        int idx = 2, pre = head->val;

        head = head->next;
        while (head && head->next)
        {
            if((head->val < pre && head->val < head->next->val) ||
                (head->val > pre && head->val > head->next->val))
            {
                ptr.push_back(idx);
            }
            pre = head->val,idx++;
            head = head->next;
        }

        if(ptr.size() > 1)
        {
            res[0] = INT_MAX;
            for(int i = 1; i < ptr.size();i++) res[0] = min(res[0],ptr[i] - ptr[i-1]);
            res[1] = ptr.back() - ptr.front();
        }
        return res;
    }
};
// @lc code=end
/*
[3,1]\n
[5,3,1,2,5,1,2]\n
[1,3,2,2,3,2,2,2,7]\n
[2,2,1,3]\n
*/