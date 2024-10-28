/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char ch =s[i];
            if(ch=='(' ||  ch!=')'){
                st.push(ch);
            }

            if(ch==')' && !st.empty()){
                string temp ="";
                while(st.top()!='('){
                     temp += st.top();
                    st.pop();
                }
                st.pop();

                if(st.empty() && i==s.length()-1){
                    return temp;
                }else{
                    for(int i=0;i<temp.length();i++){
                        st.push(temp[i]);
                    }
                }
            }
        }
        
        string ans ="";
        while(!st.empty()){
            ans+=st.top();
            if(st.top()=='(' || st.top()==')'){
                return "";
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
// @lc code=end
/*
"(abcd)"\n
"(u(loe)ai)"\n
"(ed(et(oc))el)"\n
*/
