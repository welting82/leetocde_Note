/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    // time/space: O(n)/O(1)
    bool isPalindrome(ListNode* head) {
        // find the middle node
        ListNode *slow = head, *fast = head;
        while ((fast != NULL) && (fast->next != NULL)) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half part
        ListNode *prev = NULL, *curr = slow;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // compare between left and right
        ListNode *left = head, *right = prev;
        while ((left != NULL) && (right != NULL)) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        
        return true;
    }
};
// @lc code=end
