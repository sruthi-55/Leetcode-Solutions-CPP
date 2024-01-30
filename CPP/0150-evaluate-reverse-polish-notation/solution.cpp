class Solution {
public:
    int solve(int a,int b,string op){
        if(op=="+") return a+b;
        else if(op=="-")    return a-b;
        else if(op=="*")    return a*b;
        else    return a/b;
    }
    bool isOperand(string c){
        return c=="+" || c=="-" || c=="*" || c=="/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(!isOperand(tokens[i])){
                st.push(stoi(tokens[i]));
            }
            else{
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = solve(a,b,tokens[i]);
                st.push(res);
            }
        }
        return st.top();
    }
};
