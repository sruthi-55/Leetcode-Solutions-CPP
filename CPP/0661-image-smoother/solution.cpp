class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>> res(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int totSum=0,count=0;
                for(int x=max(0,i-1); x<=min(n-1,i+1); x++){
                    for(int y=max(0,j-1); y<=min(m-1,j+1); y++){
                        totSum += img[x][y];
                        count++;
                    }
                }
                res[i][j]= totSum/count;
            }
        }
        return res;
    }
};
