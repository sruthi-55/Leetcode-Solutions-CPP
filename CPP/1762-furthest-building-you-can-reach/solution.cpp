class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {      
        int n = heights.size();
    
        priority_queue<int> pq;
        int i = 0;
        for(  ;i<=n-2;i++) {
            if(heights[i] >= heights[i+1])  continue;
            
            int diff = heights[i+1]-heights[i];
            //if bricks are enough use them
            if(diff <= bricks) {
                bricks -= diff;
                pq.push(diff); 
            } 
            //else exchange prev_max_brickUsage with ladders 
            //if prev usage is more than required bricks
            else if(ladders > 0) {
                if(!pq.empty()) {
                    int prev_max_brickUsage = pq.top();
                    if(prev_max_brickUsage > diff) {
                        //exchange with previous max brick usage
                        bricks += prev_max_brickUsage;
                        pq.pop();
                        pq.push(diff);
                        ladders--;
                        bricks -= diff;
                    }
                    else    ladders--;
                }
                else    ladders--; //either used in past or present
            } 
            else    break;
        }
        return i;
    }
};
