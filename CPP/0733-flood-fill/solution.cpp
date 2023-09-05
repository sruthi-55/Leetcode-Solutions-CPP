class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int initialColor=image[sr][sc];
        int n=image.size(),m=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        ans[sr][sc]=color;
        while(!q.empty()){
            int nodeI=q.front().first;
            int nodeJ=q.front().second;
            q.pop();
            int dI[4]={1,0,-1,0};
            int dJ[4]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int neiI=nodeI+dI[i];
                int neiJ=nodeJ+dJ[i];
                if(neiI>=0 && neiJ>=0 && neiI<n && neiJ<m && 
                image[neiI][neiJ]==initialColor && ans[neiI][neiJ]!=color){
                    q.push({neiI,neiJ});
                    ans[neiI][neiJ]=color;
                }
            }
        }
        return ans;
    }
};
