class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=0;
        int n=nums.size();
        if(nums.size()<2)   return 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    long long prod = (nums[i]-nums[j]);
                        prod=prod*nums[k];
                    maxi=max(maxi,prod);
                }
            }
        }
        if(maxi==-1)    return 0;
        return maxi;
    }
};
