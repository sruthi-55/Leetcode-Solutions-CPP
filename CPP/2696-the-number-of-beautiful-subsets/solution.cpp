class Solution {
public:
    int count;
    void getCountOfBeautifulSubsets(int i,vector<int>& nums,unordered_map<int,int> &mp,int k){
        if(i==nums.size()){
            count++;
            return ;
        }

        //not take
        getCountOfBeautifulSubsets(i+1,nums,mp,k); 
         
        //take
        if(mp[nums[i]-k]==0 && mp[nums[i]+k]==0){
            mp[nums[i]]++;
            getCountOfBeautifulSubsets(i+1,nums,mp,k);
            mp[nums[i]]--;
        }
           
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        count=0;
        unordered_map<int,int> mp;
        getCountOfBeautifulSubsets(0,nums,mp,k);
        return count-1;
    }
};
