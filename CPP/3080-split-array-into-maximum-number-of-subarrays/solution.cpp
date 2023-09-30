class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int count=0;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++)    sum=sum&nums[i];
        if(sum!=0)  return 1;
        
        
        unordered_map<int,int> prefix;
        sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(sum==0){
                count++;
                sum=nums[i];
            }
            else sum=sum&nums[i];
        }
        if(sum==0)  return count+1;
        return count;
    }
};
