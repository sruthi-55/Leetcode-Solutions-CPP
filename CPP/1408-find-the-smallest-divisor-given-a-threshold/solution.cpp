class Solution {
public:
    int getSum(int d,vector<int> &nums){
        int sum=0;
        for(auto n:nums){
            sum+= ceil((double)n/(double)d);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()>threshold)   return -1;
        int l=1,h=*max_element(nums.begin(),nums.end());
        int ans=h;
        while(l<=h){
            int mid=(l+h)/2;
            if(getSum(mid,nums)<=threshold){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
