class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //Backtracking solution
        //try all possible combinations (Recursion)
        //if open==n && close==n then, add it to res
        //if open<n then only can add '('
        //if close<open then only can add ')'
        vector<string> res;
        helper(0,0,n,"",res);
        return res;
    }
    void helper(int open,int close,int n,string str,vector<string> &res){
        if(open==n && close==n){
            res.push_back(str);
            return;
        }    
        if(open<n){
            str+="(";
            helper(open+1,close,n,str,res);
            str.pop_back();
        } 
        if(close<open){
            str+=")";
            helper(open,close+1,n,str,res);
            str.pop_back();
        } 
    }
};
