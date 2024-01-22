class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> count(n+1,0);
        for(auto e:nums)    count[e]++;

        int repN=-1,missN=-1;
        for(int i=1;i<=n;i++){
            if(count[i]==2) repN=i;
            if(count[i]==0) missN=i;
        }
        return {repN,missN};
    }
};
