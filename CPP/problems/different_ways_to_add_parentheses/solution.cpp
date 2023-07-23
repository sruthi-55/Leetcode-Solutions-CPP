class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        //try all possible ways --> Recursion
        //split at operators and solve recursively for left and right substrings
        vector<int> res;
        for(int i=0;i<exp.length();i++){
            if(exp[i]=='*'||exp[i]=='-'||exp[i]=='+'){
                vector<int> left=diffWaysToCompute(exp.substr(0,i));
                vector<int> right=diffWaysToCompute(exp.substr(i+1));
                for(int l:left){
                    for(int r:right){
                        if(exp[i]=='*') res.push_back(l*r);
                        if(exp[i]=='+') res.push_back(l+r);
                        if(exp[i]=='-') res.push_back(l-r);
                    }
                }
            }
        }
        if(res.size()==0)   res.push_back(stoi(exp));
        return res;
    }
};