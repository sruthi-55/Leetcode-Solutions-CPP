class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = 1e9;
        int ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        for(int i=0;i<=n-3;i++){
            int l=i+1,h=n-1;
            while(l<h){
                int sum = nums[i]+nums[l]+nums[h];
                int diff = abs(target-sum);
                if(diff<minDiff){
                    minDiff=diff; 
                    ans=sum;
                }   
                
                if(sum<target)  l++;
                else    h--;
            }
        }
        return ans;
    }
};
