class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int used = 0;
        priority_queue<int> pq;
        int maxReach = startFuel;

        int i=0;
        while(maxReach<target){
            while(i<stations.size() && stations[i][0]<=maxReach){
                pq.push(stations[i][1]);
                i++;
            }

            if(pq.empty())    return -1;
            int fuel = pq.top();    pq.pop();
            used++;
            maxReach += fuel;
        }
        return used;
    }
};
