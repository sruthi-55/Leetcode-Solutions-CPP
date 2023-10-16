class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n=rowIndex;
        vector<vector<int>> table(n+1);

        for(int i=0;i<=n;i++){
            table[i] = vector<int>(i+1,1);
            for(int j=1;j<i;j++){
                table[i][j]= table[i-1][j-1]+table[i-1][j];
            }
            if(i==n)    return table[i]; 
        }
        return {};
    }
};
