/*
 * @lc app=leetcode id=1669 lang=cpp
 *
 * [1669] Merge In Between Linked Lists
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *lend = list1, *str;
        for (int i = 0; i < b+1; i++)
        {
            if(i == max(0,a-1)) str = lend;
            lend = lend->next;
        }
        str->next = list2;
        while(list2->next) list2 = list2->next;
        list2->next = lend;
        return list1;
    }
};
// @lc code=end
/*
[10,1,13,6,9,5]\n
3\n
4\n
[1000000,1000001,1000002]\n

[0,1,2,3,4,5,6]\n
2\n
5\n
[1000000,1000001,1000002,1000003,1000004]\n

[0,1,2,3]\n
1\n
1\n
[1000000,1000001,1000002,1000003,1000004]\n

[0,1,2,3]\n
1\n
2\n
[1000000,1000001,1000002,1000003,1000004]\n

[0,1,2,3]\n
1\n
2\n
[1000000]\n
*/
