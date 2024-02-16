class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        for(auto e:arr) freq[e]++;

        vector<int> counts;
        for(auto e:freq)  counts.push_back(e.second);
        sort(counts.begin(),counts.end());

        int toRemove = k;
        for(int i=0;i<counts.size();i++){
            if(toRemove>=counts[i])  toRemove-=counts[i];
            else    return counts.size()-i; 
        }
        return 0;
    }
};
