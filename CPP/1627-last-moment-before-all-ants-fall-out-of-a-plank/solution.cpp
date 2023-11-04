class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxT = 0;
        for(int i=0;i<left.size();i++){
            int timeReqL = left[i];
            maxT = max(maxT,timeReqL);
        }
        for(int i=0;i<right.size();i++){
            int timeReqR = n-right[i];
            maxT = max(maxT,timeReqR);
        }
        return maxT;
    }
};
