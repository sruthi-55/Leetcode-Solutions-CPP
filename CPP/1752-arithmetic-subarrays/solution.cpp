class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for(int j=0;j<l.size();j++){
            vector<int> rangeV(nums.begin()+l[j],nums.begin()+r[j]+1);
            sort(rangeV.begin(),rangeV.end());
            
            int diff=rangeV[1]-rangeV[0];
            bool isArithmetic=true;
            for(int i=1;i<rangeV.size();i++){
                if(rangeV[i]-rangeV[i-1]!=diff)     isArithmetic=false;
            }
            res.push_back(isArithmetic==true);
        }
        return res;
    }
};
