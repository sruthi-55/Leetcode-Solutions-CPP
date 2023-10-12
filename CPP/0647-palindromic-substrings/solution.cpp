class Solution {
public:
    bool isPalindrome(int i,int j,string s){
        while(i<j){
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)) count++;
            }
        }
        return count;
    }
};
