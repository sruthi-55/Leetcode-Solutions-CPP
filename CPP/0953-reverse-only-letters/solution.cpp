class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0,h=s.size()-1;
        while(l<h){
            while(l<h && !isalpha(s[l]))  l++;
            while(l<h && !isalpha(s[h])) h--;
            swap(s[l],s[h]);
            l++;h--;
        }
        return s;
    }
};
