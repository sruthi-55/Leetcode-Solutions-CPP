class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        // 4, 3, 2,-1
        // 3, 2, 1,-1
        // 1, 1,-1,-2
        //-1,-1,-2,-3
        int n=grid.size(),m=grid[0].size();
        //start at bottom left cell
        //move top and right accordingly
        int i=n-1,j=0;
        //until cell is valid
        while(i>=0 && j<m){
            //if negative
            if(grid[i][j]<0){
                ans+=(m-j);
                i=i-1;
            }
            else if(grid[i][j]>=0)   j=j+1;
        }
        return ans;
    }
};


