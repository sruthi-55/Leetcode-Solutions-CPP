class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans = 0;
        int rows=matrix.size(),cols=matrix[0].size();
        vector<int> heights(cols,0);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==1) heights[j]+=1;
                else    heights[j]=0;
            }
            
            vector<int> sorted=heights;
            sort(sorted.begin(),sorted.end(),greater<int>());
            for(int k=0;k<cols;k++){
                ans=max(ans,(k+1)*sorted[k]);
            }
        }
        return ans;
    }
};


