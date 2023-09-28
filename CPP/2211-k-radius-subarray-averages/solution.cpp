class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res(n,-1);
        int windowSize= 2*k+1;

        int i=0;
        long long sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            if(j-i+1== windowSize){
                res[j-k]=sum/windowSize;
                sum-=nums[i];
                i++;
            }
        }
        return res;
    }
};
