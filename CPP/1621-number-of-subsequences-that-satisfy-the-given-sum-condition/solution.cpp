class Solution {
public:
    int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> power;
        power.push_back(1);
        for(int i=1;i<=n;i++){
            power.push_back((power.back()<<1)%mod);
        }
        int ans=0;
        sort(nums.begin(),nums.end());
        int l=0,h=nums.size()-1;
        while(l<=h){
            while(l<=h && nums[l]+nums[h]>target)   
                h--;
            if(l<=h){
                ans=(ans+power[h-l])%mod;
            }
            l++;
        }
        return ans%mod;
    }
    
};
