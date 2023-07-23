class Solution {
public:
    bool closeStrings(string s1, string s2) {
        //HINT:
        //Operation 1 allows you to freely reorder the string.
        // ----> strings should have same number of unique letters
        //Operation 2 allows you to freely reassign the letters' frequencies.
        // ----> sorted frequencies are equal
        vector<int> freq1(26), freq2(26);
        vector<int> unique1(26), unique2(26);
        for (char c : s1) {
            unique1[c - 'a'] = 1;
            freq1[c - 'a']++;
        }
        for (char c : s2) {
            unique2[c - 'a'] = 1;
            freq2[c - 'a']++;
        }
        if (unique1 != unique2) return false;
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1 == freq2;
    }
};
