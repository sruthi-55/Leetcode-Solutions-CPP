class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2,-1));
        for(int i=0;i<n && i+2<n;i++){
            for(int j=0;j<n && j+2<n;j++){
                int maxVal = INT_MIN;
                for(int I=i;I<i+3;I++){
                    for(int J=j;J<j+3;J++){
                        maxVal = max(maxVal,grid[I][J]);
                    }
                }
                ans[i][j]=maxVal;
            }
        }
        return ans;
    }
};
