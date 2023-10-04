class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        //n rows and m columns
        int n=matrix.size(),m=matrix[0].size();
        int top=0,bottom=n-1;
        int left=0,right=m-1;

        while(res.size()<n*m){
            for(int i=left; i<=right&&res.size()<n*m; i++){
                res.push_back(matrix[top][i]);
            }
            for(int i=top+1; i<=bottom-1&&res.size()<n*m; i++){
                res.push_back(matrix[i][right]);
            }
            for(int i=right; i>=left&&res.size()<n*m; i--){
                res.push_back(matrix[bottom][i]);
            }
            for(int i=bottom-1; i>=top+1&&res.size()<n*m; i--){
                res.push_back(matrix[i][left]);
            }
            left++;right--;top++;bottom--;
        }
        return res;
    }
};
