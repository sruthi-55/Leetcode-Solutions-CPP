class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n=nums.size();
        if(n%2==1) return false;
        
        unordered_map<int,int> freq;
        for(auto e:nums)    freq[e]++;
        
        for(auto e:freq){
            if(e.second>2)  return false;
        }
        return true;
    }
};
