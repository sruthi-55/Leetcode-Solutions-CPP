class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;
        int x0 = points[0][0], y0 = points[0][1];
        for(int i=1;i<points.size();i++){
            int x1 = points[i][0], y1 = points[i][1];
            int x_diff = abs(x1-x0), y_diff = abs(y1-y0);
            //if x difference is small
            if(min(x_diff,y_diff)==x_diff){
                totalTime += x_diff;
                totalTime += abs(y_diff-x_diff);
            }
            //if y difference is small
            else{
                totalTime += y_diff;
                totalTime += abs(x_diff-y_diff);
            }
            x0=x1,y0=y1;
        }
        return totalTime;
    }
};
