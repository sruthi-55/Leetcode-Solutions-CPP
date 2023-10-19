class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long totalCost=0;
        //min heap
        priority_queue<int, vector<int>, greater<int>> left,right;

        int count=0;
        int i=0,j=costs.size()-1;
        //select candidate with minimum cost, k times
        while(count!=k){
            while(left.size()<candidates && i<=j)   left.push(costs[i++]);
            while(right.size()<candidates && i<=j)  right.push(costs[j--]);
            int leftMin = left.size() ? left.top() : INT_MAX;
            int rightMin = right.size() ? right.top() : INT_MAX;

            if(leftMin<=rightMin){
                totalCost+=leftMin;
                left.pop();
            }
            else{
                totalCost+=rightMin;
                right.pop();
            }
            count++;
        }
        return totalCost;
    }
};
