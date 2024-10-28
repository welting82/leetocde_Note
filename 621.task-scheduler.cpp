/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0, Dtsk = 0, curr = 0, diff;
        vector<int> tbl(26,INT_MAX);

        for(int i:tasks) 
        {
            if(tbl[i - 65] == INT_MAX) tbl[i - 65] = 1, Dtsk++;
            else tbl[i - 65]++;
        }

        sort(tbl.begin(),tbl.end());
        
        while(Dtsk > 0)
        {
            cout<<diff<<" "<<res<<" "<<curr<<" "<<Dtsk<<" "<<tbl[0]<<endl;
            if(tbl[0] > curr)
            {
                diff = max(0, n - Dtsk + 1);
                res += ((Dtsk+ diff) * (tbl[0] - curr));
                curr += (tbl[0] - curr);
            }
            Dtsk--;
            cout<<"aaa"<<diff<<" "<<res<<" "<<curr<<" "<<Dtsk<<" "<<tbl[0]<<endl;
            if(Dtsk != 0) tbl.erase(tbl.begin(),tbl.begin()+1);
        }

        return res - diff;
    }
};
// @lc code=end
/*
["A","A","A","A","B","B","B","C","C"]\n
2\n
["A","A","A","B","B","B"]\n
2\n
["A","C","A","B","D","B"]\n
1\n
["A","A","A", "B","B","B"]\n
3\n
["A","A","A","A","A","A","B","C","D","E","F","G"]\n
1\n
*/
