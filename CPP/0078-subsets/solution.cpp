class Solution {
public:
    void getAllSubsets(int i,vector<int>& nums,vector<int>& subset,vector<vector<int>>& allSubsets){
        if(i==nums.size()){
            allSubsets.push_back(subset);
            return ;
        }

        subset.push_back(nums[i]);
        getAllSubsets(i+1,nums,subset,allSubsets);
        subset.pop_back();
        getAllSubsets(i+1,nums,subset,allSubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> subset;
        getAllSubsets(0,nums,subset,allSubsets);
        return allSubsets;
    }
};
