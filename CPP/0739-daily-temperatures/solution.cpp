class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        int maxI = n-1;
        for(int i=n-2;i>=0;i--){
            if(temperatures[i] >= temperatures[maxI])    maxI = i;
            else{
                int j=1;
                while(j<n && temperatures[i+j] <=  temperatures[i]){
                    j += res[i + j];
                }
                res[i] = j;
            }    
        }
        return res;
    }
};
