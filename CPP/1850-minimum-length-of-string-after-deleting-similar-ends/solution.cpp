class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int l=0,h=n-1;
        while(l<h){
            if(s[l]==s[h]){
                while(l<h && s[l]==s[l+1]) l++;
                while(l<h && s[h]==s[h-1]) h--;
                l++;h--;
            }  
            else    break;
        }
        if(h<l) return 0;
        return h-l+1;
    }
};
