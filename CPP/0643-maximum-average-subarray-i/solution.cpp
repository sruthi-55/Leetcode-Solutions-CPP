class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAverage=INT_MIN;
        int n=nums.size();

        int sum=0;
        int i=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            if(j-i+1==k){
                maxAverage=max(maxAverage,(double)sum/k);
                sum-=nums[i];
                i++;
            }
        }
        if(maxAverage==INT_MIN) return nums[0];
        return maxAverage;
    }
};
