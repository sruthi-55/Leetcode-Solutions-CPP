class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& img) {
        for(int i=0;i<img.size();i++){
            int n=img[i].size();
            for(int j=0;j<(n+1)/2;j++){
                int temp=img[i][j];
                img[i][j]=1-img[i][n-j-1];
                img[i][n-j-1]=1-temp;
            }
        }
        return img;
    }
};
