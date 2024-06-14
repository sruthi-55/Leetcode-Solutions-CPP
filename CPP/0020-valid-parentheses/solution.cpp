class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='[' || s[i]=='{' || s[i]=='(')	st.push(s[i]);
            else{
                if(st.empty())	return false;
                else{
                    char topChar = st.top();	
                    if(s[i]==']' && topChar!='[')	return false;
                    else if(s[i]==')' && topChar!='(')	return false;
                    else if(s[i]=='}' && topChar!='{')	return false;
                    else	st.pop();	
                }
            }	
        }
            
        if(st.empty())	return true;
        return false;   
    }
};
