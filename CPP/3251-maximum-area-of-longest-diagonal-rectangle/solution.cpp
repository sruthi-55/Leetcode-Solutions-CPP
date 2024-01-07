class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxD = 0,maxA = 0;;
        for(int i=0;i<dimensions.size();i++){
            int l = dimensions[i][0];
            int h = dimensions[i][1];
            
            int area = l*h;
            double diagonal = (double)sqrt(l*l+h*h);
            
            if (maxD < diagonal) {
                maxD = diagonal;
                maxA = area;
            }
            else if(maxD==diagonal){
                if(maxA<area){
                    maxA=area;
                }
            }
        }
        return maxA;
    }
};
