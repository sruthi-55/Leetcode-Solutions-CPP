class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2) return false;

        unordered_map<int,int> prefixRem;
        prefixRem[0]=-1;

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(prefixRem.find(rem)!=prefixRem.end()){
                int prevI=prefixRem[rem];
                if(i-prevI >= 2)  return true; 
            }
            //we need max possible length 
            //so we update only if remainder not found before
            else    prefixRem[sum%k]=i;
        }
        return false;
    }
};
