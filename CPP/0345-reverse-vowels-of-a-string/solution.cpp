class Solution {
public:
    bool isVowel(char c){
        c=tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    string reverseVowels(string s) {
        int l=0,h=s.size()-1;
        while(l<h){
            while(l<h && !isVowel(s[l]))    l++;
            while(l<h && !isVowel(s[h]))    h--;
            swap(s[l],s[h]);
            l++,h--;
        }
        return s;
    }
};
