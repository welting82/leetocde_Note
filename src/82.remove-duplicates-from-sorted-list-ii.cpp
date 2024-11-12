/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * res = new ListNode(0,head);
        ListNode * curr = res->next;
        ListNode * pre = res;
        int dup = 101;
        
        while (curr && curr->next)
        {
            if(curr->val != curr->next->val && curr->val != dup)
            {
                pre->next = curr;
                pre = pre ->next;
            }
            else dup = curr->val;
            curr = curr->next;
        }
        
        return res->next;
    }
};
// @lc code=end

