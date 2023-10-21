class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int ans=nums[0];    //non-empty subsequence
        //value,index
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        
        for(int i=1;i<nums.size();i++){
            //moving window to right
            //i.e trimming out of range values from left
            while(i-pq.top().second > k)    pq.pop();
            
            int curSum = nums[i] + max(0,pq.top().first);
            ans = max(ans,curSum);
            pq.push({curSum,i});
        }
        return ans;
    }
};
