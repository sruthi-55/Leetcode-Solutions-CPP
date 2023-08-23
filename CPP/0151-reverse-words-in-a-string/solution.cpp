class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n=s.length();
        for(int i=0;i<n;){
            while(i<n && s[i]==' ') i++;
            int j=i;
            while(j<n && s[j]!=' ') j++;
            if(i>=n)    break; 
            
            if(res.length()==0) res=s.substr(i,j-i);
            else    res=s.substr(i,j-i)+" "+res;
            i=j;
        }
        return res;
        
        // , ,h,e,l,l,o, ,w,o,r,l,d, , //
        //res=world hello
    }
};
