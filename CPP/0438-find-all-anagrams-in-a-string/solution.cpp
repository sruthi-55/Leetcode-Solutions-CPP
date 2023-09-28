class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> window(26),pattern(26);
        int lenP=p.size();
        if(lenP>s.size())   return res;

        //for first window
        for(int i=0;i<p.size();i++){
            //store mask for pattern
            pattern[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        if(pattern == window)   res.push_back(0);

        //move window
        for(int i=p.size();i<s.size();i++){
            //remove from left
            window[s[i-lenP]-'a']--;
            //add to right
            window[s[i]-'a']++;
            if(window == pattern)   res.push_back(i-lenP+1);
        }
        return res;
    }
};
