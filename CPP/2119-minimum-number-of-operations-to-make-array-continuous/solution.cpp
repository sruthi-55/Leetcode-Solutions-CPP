class Solution {
public:
    int minOperations(vector<int>& nums) {
        int minOp=INT_MAX;
        int n=nums.size();

        set<int> st(nums.begin(),nums.end());
        vector<int> temp(st.begin(),st.end());
        //removed duplicates and sorted array
        for(int i=0;i<temp.size();i++){
            int op=0;
            int mini=temp[i];
            int maxi=mini+n-1;
            
            //so [i,j) elements ar in range for considered mini,maxi
            //in raneg elements = (j-1-i+1) = (j-i)
            //so we need to change remaining elements which are not in range
            //i.e  n-(j-i)
            int j=upper_bound(temp.begin(),temp.end(),maxi)-temp.begin();
            op = n-(j-i);
            minOp=min(minOp,op);
        }
        return minOp;
    }
};
