class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto e:arr) mp[e]++;

        set<int> st;
        for(auto e:mp) st.insert(e.second);
        return st.size()==mp.size();
    }
};
