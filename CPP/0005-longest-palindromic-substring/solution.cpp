class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j])  return false;
            i++;j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.length(); 
        int maxLen=INT_MIN;
        int startI=0;
        
        vector<string> substrings;
        if (s.length() == 1) 
            substrings.push_back(s);
        if (s.length() == 2)
            substrings.push_back(s.substr(0, 1));

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        startI=i;
                    }
                }   
            }
        }
        
        return s.substr(startI,maxLen);
    }
};
