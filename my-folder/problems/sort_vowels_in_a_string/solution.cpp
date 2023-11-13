class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    string sortVowels(string s) {
        vector<int> vowels;
        for(auto c:s){
            if(isVowel(c))  vowels.push_back(c);
        }
        sort(vowels.begin(),vowels.end());
        int j=0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i]))  s[i]=vowels[j++];
        }
        return s;
    }
};