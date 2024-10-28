/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode();
        ListNode* even = new ListNode();
        ListNode *odd_str, *even_str;

        odd_str = odd, even_str = even;
        while(head)
        {
            odd->next = head;
            even->next = head->next;
            odd = odd->next;
            even = even->next;

            if(head->next) head = head->next->next;
            else break;
            
        }
        
        odd->next = even_str->next;
        return odd_str->next;
    }
};
// @lc code=end
/*
[1,2,3,4,5]\n
[2,1,3,5,6,4,7]\n
[2,1,3,5,6,4]\n
*/
