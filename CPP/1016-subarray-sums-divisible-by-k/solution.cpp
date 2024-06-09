class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;

        unordered_map<int,int> prefixMap;
        prefixMap[0]=1;

        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int req = sum%k;
            if(req<0)   req+=k;

            if(prefixMap.find(req)!=prefixMap.end()){
                count += prefixMap[req];
            }
            prefixMap[req]++;
            
        }
        return count;
    }
};

