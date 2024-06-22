class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;

        int curOdds = 0;
        int niceSubArrs = 0;
        for(int i=0;i<nums.size();i++){
            curOdds += (nums[i]%2);

            int req = curOdds-k;
            if(mp.find(req)!=mp.end()){
                niceSubArrs += mp[req];
            }
            mp[curOdds]++;
        }
        return niceSubArrs;
    }
};
