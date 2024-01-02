class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;

        for(auto e:mp){
            int row = 0;
            int count=e.second;
            while(count!=0){
                if(res.size()<=row)
                    res.push_back({e.first});
                else    res[row].push_back(e.first);
                count--;
                row++;
            }
        }
        return res;
    }
};
