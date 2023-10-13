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
            int req=sum%k;
            if(prefixRem.find(req)!=prefixRem.end()){
                int prevI=prefixRem[req];
                if(i-prevI>1) return true; 
            }
            //we need max possible length 
            //so we don't update if we already got same remainder before
            else    prefixRem[sum%k]=i;
        }
        return false;
    }
};
