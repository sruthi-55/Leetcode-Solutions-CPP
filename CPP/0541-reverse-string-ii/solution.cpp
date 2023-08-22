class Solution {
public:
    string reverseStr(string s, int k) {
        int l=0;
        int h= min(k,(int)s.size());
        while(l<s.length()){
            reverse(s.begin()+l,s.begin()+h);
            l+=2*k;
            h= min(l+k,(int)s.size());
        }
        return s;
    }
};
