class Solution {
public:
    int isVowel(char c){
        return c=='a' | c=='e' | c=='i' | c=='o' | c=='u';
    }
    int maxVowels(string s, int k) {
        int ans=0;

        int i=0;
        int count=0;
        for(int j=0;j<s.size();j++){
            if(isVowel(s[j]))  count++;

            if(j-i+1==k){
                ans=max(ans,count);
                if(isVowel(s[i]))  count--;
                i++;
            }
        }
        return ans;
    }
};
