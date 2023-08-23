class Solution {
public:
    void reverse(string &s,int i,int j){
        while(i<j){
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;j--;
        }
    }
    string reverseWords(string s) {
        int n=s.size();
        for(int i=0;i<n;){
            while(i<n && s[i]==' ') i++;
            int j=i;
            while(j<n && s[j]!=' ')    j++;
            if(i>=n)    break;
            reverse(s,i,j-1);
            i=j;
        }
        return s;
    }
};
