class Solution {
public:
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int,long> rootCountM;
        rootCountM[arr[0]] = 1;
        for(int i=1;i<arr.size();i++){
            long count = 1;
            int rootEle = arr[i];
            //par, leftC, rightC
            //rootEle, arr[j], rootEle/arr[j]
            for(int j=0;j<i;j++){
                if(rootEle%arr[j] == 0 
                && rootCountM.find(rootEle/arr[j]) != rootCountM.end()){
                    count += rootCountM[arr[j]] * rootCountM[rootEle/arr[j]];
                }
            }
            rootCountM[rootEle] = count;
        }
        int noOfTrees = 0;
        for(auto entry : rootCountM){
            noOfTrees = (noOfTrees + entry.second) % mod;
        }
        return noOfTrees;
    }
};
