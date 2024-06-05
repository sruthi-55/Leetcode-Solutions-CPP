class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int chars[26] = {0};
        for(int i=0;i<words[0].size();i++)  
            chars[words[0][i]-'a']++;

        for(int i=1;i<words.size();i++){
            int temp[26] = {0};
            for(auto c:words[i]){
                temp[c-'a']++;
            }
            for(int i=0;i<26;i++){
                chars[i] = min(chars[i],temp[i]);
            }
        }

        vector<string> res;
        for(int i=0;i<26;i++){
            if(chars[i]){
                int c = chars[i];
                while(c--) {
                    res.push_back(string(1, i+'a'));
                }
            }
        }
        return res;
    }
};
