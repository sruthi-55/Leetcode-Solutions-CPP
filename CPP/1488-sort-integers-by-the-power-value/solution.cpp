class Solution {
public:
    static bool customComparator(pair<int, int> &a,pair<int, int> &b){
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second<b.second;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> res;
        for(int i=lo;i<=hi;i++){
            res.push_back({i,getCount(i)});
        }
        sort(res.begin(),res.end(),customComparator);
        return res[k-1].first;
    }
    int getCount(int k){
        int count=0;
        while(k!=1){
            if(k%2==0)  k=k/2;
            else    k=3*k+1;
            count++;
        }
        return count;
    }
};
