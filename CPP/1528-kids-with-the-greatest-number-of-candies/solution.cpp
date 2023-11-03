class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        vector<bool> res;
        int maxi = *max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++){
            if(candies[i]==maxi)   res.push_back(true);
            else if(candies[i]+extra>=maxi)   res.push_back(true);
            else    res.push_back(false);
        }
        return res;
    }
};
