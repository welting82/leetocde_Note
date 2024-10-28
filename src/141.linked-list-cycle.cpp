/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *l = head, *r = head;
        if(!head) return false;

        while (r->next && r->next->next)
        {
            l = l->next;
            r = r->next->next;
            if(l == r) return true;
        }
        return false;
    }
};
// @lc code=end
/*
[1,2]\n
-1\n
[1,2]\n
0\n
[1]\n
0\n
[1,2,3,4]\n
0\n
[1]\n
-1\n
[]\n
-1\n
[-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5]\n
-1\n
*/
