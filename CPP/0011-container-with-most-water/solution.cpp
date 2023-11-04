class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxa=0;
        int l=0,h=heights.size()-1;
        while(l<=h){
            int area = min(heights[l],heights[h])*(h-l);
            maxa = max(maxa,area);
            if(min(heights[l],heights[h])==heights[l])  l++;
            else    h--;
        }
        return maxa;
    }
};
