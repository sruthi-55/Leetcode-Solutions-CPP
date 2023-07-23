class Solution {
public:
    bool buddyStrings(string s, string t) {
        if(s.length()!=t.length())    return false;
        int n=s.length();
        int ind1=-1,ind2=-1;
        //s="aa"
        //t="aa"
        if(s==t){
            set<char> temp(s.begin(),s.end());
            return temp.size()<t.size();
        }
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                if(ind1==-1) ind1=i;
                else    ind2=i;
            }
        }
        if(ind1!=-1 && ind2!=-1)    swap(s[ind1],s[ind2]);
        else    return false;
        return s==t;
    }
};
