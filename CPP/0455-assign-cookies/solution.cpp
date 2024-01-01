class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0;
        for(int i=0;i<g.size() && j<s.size();j++){
            if(g[i]<=s[j]){
                count++;
                i++;
            }
        }
        //g- 7,8,9,10
        //s- 5,6,7,8
        return count;
    }
};
