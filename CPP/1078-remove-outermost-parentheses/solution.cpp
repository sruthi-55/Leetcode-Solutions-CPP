class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int opened=0;
        for(auto c:s){
            if(c=='('){
                if(opened>=1)   ans+=c;
                opened++;
            }  
            else if(c==')'){
                if(opened>1)    ans+=c;
                opened--;
            }
        }
        return ans;
    }
};
