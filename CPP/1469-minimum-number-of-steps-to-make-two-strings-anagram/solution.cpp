class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        for(auto c:s)
            mp[c]++;
        
        int op=0;
        for(int i=0;i<t.length();i++){
            if(mp.find(t[i])!=mp.end()){
                if(mp[t[i]]>0)  mp[t[i]]--;
                else{
                    op++;
                    mp.erase(t[i]);
                }
            }  
            else{
                op++;
            }
        }
        return op;
    }
};
