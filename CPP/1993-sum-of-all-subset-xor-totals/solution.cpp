class Solution {
public:
    void generateSubsets(int i,vector<int> &nums,vector<int> &curSubset,vector<vector<int>> &allSubsets){
        if(i==nums.size()){
            allSubsets.push_back(curSubset);
            return ;
        }

        curSubset.push_back(nums[i]);
        generateSubsets(i+1,nums,curSubset,allSubsets);
        curSubset.pop_back();
        generateSubsets(i+1,nums,curSubset,allSubsets);
    }
    int subsetXORSum(vector<int>& nums) {
        int tSum = 0;
        vector<int> curSubset;
        vector<vector<int>> allSubsets;
        generateSubsets(0,nums,curSubset,allSubsets);
        for(auto subset : allSubsets){
            int xorr = 0;
            for(auto e : subset){
                xorr ^= e;
            }
            tSum += xorr;
        }
        return tSum;
    }
};
