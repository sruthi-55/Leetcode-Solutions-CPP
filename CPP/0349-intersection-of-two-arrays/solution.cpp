class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> set(nums1.begin(),nums1.end());
        for(auto a:nums2){
            if(set.find(a)!=set.end()){
                res.push_back(a);
                set.erase(a);
            }
        }
        return res;
    }
};
