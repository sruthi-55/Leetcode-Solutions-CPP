class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        //If a number appears n times, 
        //then n*(n–1)/2 good pairs can be made with this number
        int ans=0;
        unordered_map<int,int> map;
        for(auto n:nums)    map[n]++;

        for(auto entry:map){
            int freq=entry.second;
            ans+=(freq)*(freq-1)/2;
        }
        return ans;
    }
};
