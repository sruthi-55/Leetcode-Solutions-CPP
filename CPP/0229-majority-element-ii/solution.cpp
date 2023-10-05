class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        int limit=(int)n/3+1;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
            if(map[nums[i]]==limit) res.push_back(nums[i]);
            if(res.size()==2)   break;
        }
        sort(res.begin(),res.end());
        return res;
    }
};
