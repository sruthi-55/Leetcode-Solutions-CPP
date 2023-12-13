class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> row(n,0),col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==1 && col[j]==1 && mat[i][j]==1)    
                    count++;
            }
        }
        return count;
    }
};
