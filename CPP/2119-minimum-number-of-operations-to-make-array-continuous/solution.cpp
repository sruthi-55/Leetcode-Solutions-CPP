class Solution {
public:
    int minOperations(vector<int>& nums) {
        int minOp=INT_MAX;
        int n=nums.size();

        set<int> st(nums.begin(),nums.end());
        vector<int> temp(st.begin(),st.end());
        for(int i=0;i<temp.size();i++){
            int op=0;
            int mini=temp[i];
            int maxi=mini+n-1;
            
            int j=upper_bound(temp.begin(),temp.end(),maxi)-temp.begin();
            op = i+n-j;
            minOp=min(minOp,op);
        }
        return minOp;
    }
};
