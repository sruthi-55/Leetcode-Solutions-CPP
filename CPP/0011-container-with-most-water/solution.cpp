class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA=0;
        int l=0,h=height.size()-1;
        while(l<h){
            int area=min(height[h],height[l])*(h-l);
            if(area>maxA)   maxA=area;
            //increment the pointer where the bar is smaller 
            if(min(height[h],height[l])==height[l]) l++;
            else    h--;
        }
        return maxA;
    }
};
