class Solution {
public:
    vector<string> res;
    unordered_map<string,int> m;
    vector<string> removeInvalidParentheses(string s) {
        //try all possible ways --> Recursion
        //remove each char and check inValid chars in substring
        //"()())()" --> check inValid chars in [")())()", "(())()", "()))()", ...]
        solve(s,getMinInvalid(s));
        return res;
    }
    int getMinInvalid(string s){
        stack<char> st;
        for(int i:s){
            if(i=='(')  st.push(i);
            else if(i==')'){
                if(st.size()>0 && st.top()=='(')   st.pop();
                else    st.push(i);
            }
        }
        // "(a)())()"
        // st --> [)]
        return st.size();
    }
    void solve(string s,int minInv){
        if(m[s])    return;
        else    m[s]++;
        if(minInv==0){
            if(!getMinInvalid(s))   res.push_back(s);
            return;
        }
        for(int i=0;i<s.length();i++){
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            solve(left+right,minInv-1);
        }
    }
};
