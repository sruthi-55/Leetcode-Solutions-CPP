class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res=0;
        unordered_map<char,int> last;
        for(int i=0;i<garbage.size();i++){
            res+=garbage[i].size();
            for(auto c:garbage[i])  last[c]=i;
        }

        int metal = 0, paper = 0, glass = 0;
        for (int i = 1; i < garbage.size(); i++) {
            if(i<=last['M'])    metal+=travel[i-1];
            if(i<=last['P'])    paper+=travel[i-1];
            if(i<=last['G'])    glass+=travel[i-1];
        }
        res+=(metal+glass+paper);
        return res;
    }
};

