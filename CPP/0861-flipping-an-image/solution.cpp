class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        for(int i=0;i<n;i++){
            int l=0,h=n-1;
            while(l<=h){
                int temp = image[i][l];
                image[i][l] = image[i][h];
                image[i][h] = temp;
                
                if(l==h)    image[i][l] ^=1;
                else{
                    image[i][l] ^=1;
                    image[i][h] ^=1;
                }
                l++;h--;
            }
        }
        return image;
    }
};
