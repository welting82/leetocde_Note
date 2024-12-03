/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */

// @lc code=start
class TrieNode {
public:
    unordered_map<char,TrieNode*> ch;
    bool hasWord = false;
    TrieNode(){}
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    string longestWord(vector<string>& words) {
        string res = "";
        TrieNode* curr;
        root->hasWord = true;

        for(string str:words)
        {
            curr = root;
            for(char c:str)
            {
                if(!curr->ch[c]) curr->ch[c] = new TrieNode();
                curr = curr->ch[c];
            }
            curr->hasWord = true;
        }

        for(string str:words)
        {
            curr = root;
            for(char c:str)
            {
                if(!curr->hasWord) break;
                else curr = curr->ch[c];
            }
            if(curr->hasWord)
            {
                if(res.length() == str.length() && res < str) {}
                else if(res.length() <= str.length()) res = str;
            }
        }

        return res;
    }
};
// @lc code=end
/*
["w","wo","wor","worl","world"]\n
["a","banana","app","appl","ap","apply","apple"]\n
["m","mo","moc","moch","mocha","l","la","lat","latt","latte","c","ca","cat"]\n
["k","lg","it","oidd","oid","oiddm","kfk","y","mw","kf","l","o","mwaqz","oi","ych","m","mwa"]\n
*/
