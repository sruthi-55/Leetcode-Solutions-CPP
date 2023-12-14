class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> onesInRow(m,0),onesInCol(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    onesInRow[i]++;
                    onesInCol[j]++;
                }
            }
        }

        vector<vector<int>> diff(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int onesRow = onesInRow[i];
                int zeroesRow = n - onesRow;
                int onesCol = onesInCol[j];
                int zeroesCol = m - onesCol;
                diff[i][j]= onesRow + onesCol - zeroesRow - zeroesCol;
            }
        }
        return diff;
    }
};
