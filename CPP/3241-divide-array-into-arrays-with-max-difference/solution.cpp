class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<=nums.size()-3;i+=3){
            int a=nums[i], b=nums[i+1], c=nums[i+2];

            if(c-b>k || b-a>k || c-a>k)  return {};
            ans.push_back({a,b,c});
        }
        return ans;
    }
};
