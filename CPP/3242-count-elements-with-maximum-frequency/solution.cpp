class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxF=0;
        for(auto e:nums){
            maxF = max(maxF,mp[e]);
            mp[e]++;
            maxF = max(maxF,mp[e]);
        }
        
        int sum=0;
        for(auto e:mp){
            if(e.second==maxF)   sum+=e.second;
        }
        return sum;
    }
};
