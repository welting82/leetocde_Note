/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* res;
    void helper(ListNode* node) {
        if(node->next->next) helper(node->next);
        else res = node->next;
        node->next->next = node;
        return;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        helper(head);
        head->next = nullptr;
        return res;
    }
};
// @lc code=end
/*
[1,2,3,4,5]\n
[1,2]\n
[]\n
*/
