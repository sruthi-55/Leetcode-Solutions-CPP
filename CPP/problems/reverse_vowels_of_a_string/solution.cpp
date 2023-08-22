class Solution {
public:
    bool isVowel(char c){
        if(65<=c<=90){
            c = tolower(c);
        }
        if(c=='a'|| c=='e' || c=='i' || c=='o' || c=='u') return true;
        else return false;
    }
    string reverseVowels(string s) {
        int l=0,h=s.size()-1;
        while(l<h){
            while(l<h && !isVowel(s[l]))   l++;
            while(l<h && !isVowel(s[h]))   h--;
            if(l<h){
                swap(s[l],s[h]);
                l++;h--;
            }
        }
        return s;
    }
};