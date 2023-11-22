class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> map;
        for(int r=nums.size()-1;r>=0;r--) {
            for(int c=0; c<nums[r].size(); c++) {
                map[r+c].push_back(nums[r][c]);
            }
        }
        
        vector<int> result;
        int diagonal = 0;
        while(map.find(diagonal) != map.end()) {
            for(int &num : map[diagonal]) {
                result.push_back(num);
            }
            diagonal++;
        }
        return result;
    }
};
