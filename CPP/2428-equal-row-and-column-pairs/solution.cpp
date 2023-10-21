class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        map<vector<int>,int> map;
        for(int i=0;i<n;i++)
            map[grid[i]]++;

        for(int j=0;j<m;j++){
            vector<int> col;
            for(int i=0;i<n;i++){
                col.push_back(grid[i][j]);
            }
            ans+=map[col];
        }
        
        return ans;
    }
};
