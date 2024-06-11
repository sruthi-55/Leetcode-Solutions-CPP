class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto e:arr1)    mp[e]++;

        vector<int> res;
        int j=0;
        for(int i=0;i<arr2.size();i++){
            int curE = arr2[i];
            int freq = mp[curE];
            while(freq){
                res.push_back(curE);
                freq--;
            }
            mp[curE] = 0;
        }

        for(auto e:mp){
            int freq = e.second;
            int ele = e.first;
            while(freq){
                res.push_back(ele);
                freq--;
            }
        }
        return res;
    }
};
