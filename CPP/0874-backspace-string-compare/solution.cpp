class Solution {
public:
    string solve(string s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(!st.empty()) st.pop();
            }
            else    st.push(s[i]);
        }

        string newS;
        while(!st.empty()){
            newS+=st.top();
            st.pop();
        }
        reverse(newS.begin(),newS.end());
        return newS;
    }
    bool backspaceCompare(string s, string t) {
        string newS,newT;
        return solve(s)==solve(t);
    }
};
