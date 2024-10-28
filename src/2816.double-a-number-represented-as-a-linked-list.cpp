/*
 * @lc app=leetcode id=2816 lang=cpp
 *
 * [2816] Double a Number Represented as a Linked List
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
    ListNode* doubleIt(ListNode* head) {
        int sum = 0;
        ListNode* res = new ListNode(0,head);
        ListNode* idx = res;

        while (idx->next)
        {
            sum = idx->next->val * 2;
            if(sum > 9) idx->val += 1;
            idx->next->val = sum % 10; 
            idx = idx->next;
        }
        return (res->val == 0)? res->next:res;
    }
};
// @lc code=end
/*
[1,8,9]\n
[9,9,9]\n
[5,5,5]\n
[5,0,0]\n
*/
