class Solution {
public:
    string minWindow(string s, string t) {

        int minStartInd = 0;
        int minLen = INT_MAX;

        unordered_map<char,int> freq;
        for(auto c:t)   freq[c]++;

        int count = t.size();
        int i=0;
        for(int j=0;j<s.size();j++){
            if(freq[s[j]]>0){
                count--;
            }
            freq[s[j]]--;

            while(count==0){
                if(j-i+1<minLen){
                    minLen = j-i+1;
                    minStartInd = i;
                }
                
                freq[s[i]]++;
                if(freq[s[i]]>0)    count++;
                i++;
            }
        }
        if(minLen == INT_MAX)   return "";
        string ans = s.substr(minStartInd,minLen);
        return ans;
    }
};
