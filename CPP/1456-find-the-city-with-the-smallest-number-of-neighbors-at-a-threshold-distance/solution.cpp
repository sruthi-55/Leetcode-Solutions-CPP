class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)    matrix[i][i]=0;
        for(auto e:edges){
            matrix[e[0]][e[1]]=e[2];
            matrix[e[1]][e[0]]=e[2];
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][k]!=1e9 && matrix[k][j]!=1e9)
                        matrix[i][j]=min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                }
            }
        }

        int minCount=INT_MAX;
        int city=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=distanceThreshold)  count++;
            }
            if(minCount>=count){
                minCount=count;
                city=i;
            }
        }
        return city;
    }
};
