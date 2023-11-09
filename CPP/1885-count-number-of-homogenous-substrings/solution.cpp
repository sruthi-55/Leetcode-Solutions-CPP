class Solution {
public:
    int mod=1e9+7;
    int countHomogenous(string s) {
        int res=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(i>0 && s[i]==s[i-1])    count++;
            else count=1;
            res=(res+count)%mod;
        } 
        return res%mod;
    }
};
