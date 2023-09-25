class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        //need a data structure that inserts from back and removes from front 
        //store indices in deque
        
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            //if we got greater ele, then remove all ele which are smaller than this from dq
            //non-increasing dq
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);    
            
            //if window size increases(> k) remove from front
            if(dq.front()== i-k) dq.pop_front();

            //store max in result after window is formed
            if(i>=k-1)  res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
