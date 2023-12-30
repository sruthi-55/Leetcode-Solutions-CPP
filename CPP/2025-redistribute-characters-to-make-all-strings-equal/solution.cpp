class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> chars(26,0);
        for(int i=0;i<words.size();i++){
            for(auto c:words[i])
                chars[c-'a']++;
        }
        int n=words.size();
        for(int i=0;i<26;i++){
            if(chars[i]%n!=0)   return false;
        }
        return true;
    }
};
