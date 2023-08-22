class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,h=s.size()-1;
        while(l<h){
            while(l<h && !isalnum(s[l]))    l++;
            while(l<h && !isalnum(s[h]))    h--;
            if(tolower(s[l])!=tolower(s[h]))  return false;
            else    l++,h--;
        }
        return true;
    }
};
