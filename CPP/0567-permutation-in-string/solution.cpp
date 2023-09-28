class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> pattern(26),window(26);
        for(char c:s1)  pattern[c-'a']++;
        
        int i=0;
        for(int j=0;j<s2.size();j++){
            window[s2[j]-'a']++;
            if(pattern==window) return true;

            //move window
            if(j-i+1==s1.size()){
                window[s2[i]-'a']--;
                if(pattern==window) return true;
                i++;
            }
        }
        return false;
    }
};

       

