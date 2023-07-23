class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        int ind1=-1,ind2=-1;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(ind1==-1) ind1=i;
                else    ind2=i;
            }
        }
        if(ind1!=-1 && ind2!=-1)    swap(s1[ind1],s1[ind2]);
        return s1==s2;
    }
};