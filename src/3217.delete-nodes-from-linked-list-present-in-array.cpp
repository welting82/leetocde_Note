/*
 * @lc app=leetcode id=3217 lang=cpp
 *
 * [3217] Delete Nodes From Linked List Present in Array
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* res = new ListNode(0,head);
        ListNode* pre = res;

        map<int,int> mp;
        for(int i:nums) mp[i]++;

        while(head)
        {
            while(head && mp[head->val])
            {
                head = head->next;
            }
            pre->next = head;
            pre = pre->next;
            if(head) head = head->next;
        }

        return res->next;
    }
};
// @lc code=end
/*
[1,2,3]\n
[1,2,3,4,5]\n
[1]\n
[1,2,1,2,1,2]\n
[5]\n
[1,2,3,4]\n
*/
