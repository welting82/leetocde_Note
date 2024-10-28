/*
 * @lc app=leetcode id=2181 lang=cpp
 *
 * [2181] Merge Nodes in Between Zeros
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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* res = new ListNode();
        ListNode* idx = res;

        while(head)
        {
            if(head->val == 0)
            {
                if(sum != 0)
                {
                    idx->next = new ListNode(sum);
                    sum = 0;
                    idx = idx->next;
                }
            }
            else sum += head->val;
            head = head->next;
        }

        return res->next;
    }
};
// @lc code=end
/*
[0,3,1,0,4,5,2,0]\n
[0,1,0,3,0,2,2,0]\n
*/
