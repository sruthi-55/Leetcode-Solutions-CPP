class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                unordered_map<int,int> mp;
                for(int l=j+1;l<n;l++){
                    int req = -(nums[i]+nums[j]-nums[l]);
                    if(mp.find(req)!=mp.end())
                        count+=mp[req];
                    mp[nums[l]]++;
                }
            }
        }
        return count;
    }
};
