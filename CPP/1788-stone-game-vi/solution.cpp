class Solution {
public:
    int stoneGameVI(vector<int>& aliceV, vector<int>& bobV) {
        int n = aliceV.size();
        //{a+b,a,b}
        vector<vector<int>> values;
        for(int i=0;i<n;i++){
            values.push_back({aliceV[i]+bobV[i],aliceV[i],bobV[i]});
        }
        sort(values.begin(),values.end(),greater<vector<int>>());

        int aliceScore=0,bobScore=0;
        for(int i=0;i<n;i++){
            if(i%2==0) aliceScore += values[i][1];
            else    bobScore += values[i][2];
        }
        if(aliceScore>bobScore) return 1;
        else if(bobScore>aliceScore)    return -1;
        else    return 0;
    }
};
