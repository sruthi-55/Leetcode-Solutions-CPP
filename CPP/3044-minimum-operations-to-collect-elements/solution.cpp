class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operations=0;
        int count=0;
        if(nums.size()==1)  return 1;
        unordered_set<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            operations++;
            if(nums[i]<=k && st.find(nums[i])==st.end()){
                count++;
                st.insert(nums[i]);
            }  
            if(count==k)    break;
        }
        return operations;
    }
};
