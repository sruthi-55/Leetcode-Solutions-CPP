class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long res=0;
        long mod=1e9+7;
        unordered_map<int,long> m;
        for(auto i:arr)  m[i]++;
        for(auto a:m){
            for(auto b:m){
                int i=a.first,j=b.first;
                int k=target-i-j;
                if(!m.count(k)) continue;
                if(i==j && j==k)
                    res+=m[i]*(m[i]-1)*(m[i]-2)/6;
                else if(i==j && j!=k)
                    res+=m[i]*(m[i]-1)/2*m[k];
                else if(i<j && j<k)   
                    res+=m[i]*m[j]*m[k];
            }
        }
        return res%(int)(mod);
    }
};
