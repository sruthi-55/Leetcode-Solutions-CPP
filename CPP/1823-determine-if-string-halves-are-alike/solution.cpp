class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    bool halvesAreAlike(string s) {
        int firstHalf = 0, secondHalf = 0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                if(i>=s.length()/2)  secondHalf++;
                else    firstHalf++;
            }
        }
        return firstHalf == secondHalf;
    }
};
