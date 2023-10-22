class Solution {
public:
    int partitionString(string s) {
        unordered_set<int> set;
        int count=1;
        for(int i=0;i<s.size();i++){
            if(set.find(s[i])!=set.end()){
                count++;
                set.clear();
            }
            set.insert(s[i]);
        }
        return count;
    }
};
