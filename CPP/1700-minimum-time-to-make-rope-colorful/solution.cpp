class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int prev=0;
        int ans = 0;
        for(int i=1;i<n;i++){
            if(colors[prev]!=colors[i]) prev=i;
            else{
                //remove ballon with min needed time
                if(neededTime[prev]<neededTime[i]){
                    ans += neededTime[prev];
                    prev = i;
                }
                else{
                    ans += neededTime[i];
                }
            }
        }
        return ans;
    }
};
