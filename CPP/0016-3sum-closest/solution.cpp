class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum=1e9;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        for(int i=0;i<=n-3;i++){
            int l=i+1,h=n-1;
            while(l<h){
                int sum = nums[i]+nums[l]+nums[h];
                if(abs(target-sum)<abs(target-closestSum)){
                    closestSum = sum;
                }   
                
                if(sum<target)  l++;
                else    h--;
            }
        }
        return closestSum;
    }
};
