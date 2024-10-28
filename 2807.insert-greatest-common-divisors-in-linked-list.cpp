/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* res = head;
        ListNode* tmp;

        while(head && head->next)
        {
            tmp = new ListNode(__gcd(head->val, head->next->val),head->next);
            head->next = tmp;
            head = head->next->next;
        }

        return res;
    }
};
// @lc code=end
/*
[18,6,10,3]\n
[18,6,10,3,64,75,2,1,4,455,654,600,1,20,10,11,13]\n
*/
