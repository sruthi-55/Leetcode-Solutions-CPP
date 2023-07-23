class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi=0;
        //stack
        //traverse the string
        //top ele of stack == the end of inValid string
        //so, initially puhs(-1)
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')   st.push(i);
            else {
                st.pop();
                if(st.empty())    //invalid string, so push end of inValid string
                    st.push(i); 
                else    maxi=max(maxi,i-st.top());
            }
        }
        return maxi;
    }
};
