/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start

// Definition for a Node.
/*
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> umap;
    Node* copyNext(Node* head, int idx)
    {
        Node* res = nullptr;
        if(head)
        {
            res = new Node(head->val);
            res->next = copyNext(head->next, idx + 1);
        }
        umap[head] = res;
        return res;
    }

    Node* copyRandomList(Node* head) {
        Node* res;

        res = copyNext(head,0);

        while(head)
        {
            umap[head]->random = umap[head->random];
            head = head->next;
        }
        return res;
    }
};
// @lc code=end
/*
[[7,null],[13,0],[11,4],[10,2],[1,0]]\n
[[1,1],[2,1]]\n
[[3,null],[3,0],[3,null]]\n
*/
