class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums[0]+1;
        
        
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]==1){
                sum+=nums[i];
            }
            else{
                break;
            }
        }
        
        
        unordered_map<int,int> mp;
        for(auto e:nums)    mp[e]++;
        
        while(mp.find(sum)!=mp.end()){
            sum++;
        }
        return sum;
        
        
        
        
    }
};
