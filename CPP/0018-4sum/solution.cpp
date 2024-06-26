class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])   continue;
            for(int j=i+1;j<n;j++){
                if(j!=(i+1) && nums[j]==nums[j-1])   continue;
                int l=j+1,h=n-1;
                while(l<h){
                    long long s=nums[i];
                    s+=nums[j];
                    s+=nums[l];
                    s+=nums[h];
                    if(s==target){
                        vector<int> temp = {nums[i],nums[j],nums[l],nums[h]};
                        ans.push_back(temp);
                        l++;h--;

                        while(l<h && nums[l]==nums[l-1]) l++;
                        while(l<h && nums[h]==nums[h+1]) h--;
                    }
                    else if(s<target) l++;
                    else h--;
                }
            }
        }
        return ans;
    }
};
