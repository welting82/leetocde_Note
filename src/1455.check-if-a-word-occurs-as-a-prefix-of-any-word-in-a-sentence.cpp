/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
class Node
{
public:
    Node* ch[26];
    int idx;
    bool isEnd;
    Node()
    {
        for(int i = 0; i < 26; i++) ch[i] = NULL;
        idx = INT_MAX;
        isEnd = false;
    }
};

class Solution {
public:
    Node* root = new Node();
    int isPrefixOfWord(string sentence, string searchWord) {
        Node* curr;
        stringstream ss(sentence);
        string str;
        int cnt = 1;
        while(getline(ss, str, ' '))
        {
            curr = root;
            for(char i:str)
            {
                if(!curr->ch[i - 'a'])
                {
                    curr->ch[i - 'a'] = new Node();
                    curr->ch[i - 'a']->idx = cnt;
                }
                curr = curr->ch[i - 'a'];
            }
            cnt++;
            curr->isEnd = true;
        }
        for(char i:searchWord)
        {
            root = root->ch[i - 'a'];
            if(!root) return -1;
        }
        return root->idx;
    }
};
// @lc code=end
/*
"i love eating burger"\n
"burg"\n
"i am tired oiiraa"\n
"you"\n
"hello from the other side"\n
"they"\n
"love errichto jonathan dumb"\n
"dumb"\n
*/
