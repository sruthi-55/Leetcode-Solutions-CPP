class Solution {
public:
    int maxDepth(string s) {
        //keep track of opened
        int opened=0;
        int maxDepth=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                opened++;
                maxDepth=max(maxDepth,opened);
            }
            else if(s[i]==')')    opened--;
        }
        return maxDepth;
    }
};
