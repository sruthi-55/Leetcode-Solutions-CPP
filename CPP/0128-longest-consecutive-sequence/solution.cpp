class Solution {
public: 
    int longestConsecutive(vector<int>& nums) {
        int maxCount=0;
        unordered_set<int> set;
        for(auto n:nums)    set.insert(n);

        for(auto e:set){
            if(set.find(e-1)==set.end()){
                int count=1;
                while(set.find(e+1)!=set.end()){
                    count++;
                    e++;
                }
                maxCount=max(maxCount,count);
            }
        }
        return maxCount;
    }
};
