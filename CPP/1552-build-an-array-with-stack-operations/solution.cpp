class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int j=0;
        int tar_size = target.size();
        for(int i=1;i<=n && j<target.size();i++){
            if(i==target[j]){
                res.push_back("Push");
                j++;
            }    
            else{
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};
