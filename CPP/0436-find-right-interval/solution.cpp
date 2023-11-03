class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res;
        unordered_map<int,int> map;
        vector<int> firstS;
        for(int i=0;i<intervals.size();i++){
            map[intervals[i][0]]=i;
            firstS.push_back(intervals[i][0]);
        }

        sort(firstS.begin(),firstS.end());
        for(auto I:intervals){
            auto it = lower_bound(firstS.begin(),firstS.end(),I[1]);
            if(it==firstS.end()) res.push_back(-1);
            else{
                int first=*it;
                res.push_back(map[first]);
            }
        }
        return res;
    }
};
