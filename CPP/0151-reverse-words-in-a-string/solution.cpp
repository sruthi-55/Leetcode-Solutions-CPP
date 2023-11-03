class Solution {
public:
    string reverseWords(string s){
        string res="";
        int i=0,j=0;
        while(j<s.size()){
            //i points to first letter
            while(i<s.size() && s[i]==' ')  i++;
            //j points to space after word
            j=i;
            while(j<s.size() && s[j]!=' ')  j++;
            if(i>=s.size())    break; 
            
            if(res.length()==0) res=s.substr(i,j-i);
            else    res=s.substr(i,j-i)+" "+res;
            i=j;
        }
        return res;
    }
};
