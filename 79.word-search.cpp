/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool helper(vector<vector<char>>& tbl, int i, int j, string word, int idx) {
        if(i < 0 || j < 0 || i == tbl.size() || j == tbl[0].size() ||\
            tbl[i][j] != word[idx] ) return false;
        else if(idx == word.size()-1) return true;
        else
        {
            char ch = tbl[i][j];
            bool res;
            tbl[i][j] = '0';
            res =  helper(tbl,i+1,j,word,idx+1) || helper(tbl,i-1,j,word,idx+1) ||\
                    helper(tbl,i,j+1,word,idx+1) || helper(tbl,i,j-1,word,idx+1);
            tbl[i][j] = ch;
            return res;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<char>> tmp;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmp = board;
                if(helper(tmp, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};
// @lc code=end
/*
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n
"ABCCED"\n
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n
"SEE"\n
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n
"ABCB"\n
[["C","A","A"],["A","A","A"],["B","C","D"]]\n
"AAB"\n
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n
"ABCB"\n
[["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]\n
"ABCESEEEFS"\n
*/