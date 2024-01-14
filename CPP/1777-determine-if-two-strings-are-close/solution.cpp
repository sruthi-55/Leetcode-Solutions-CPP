class Solution {
public:
    bool closeStrings(string word1, string word2) {
        //HINT:
        //Operation 1 allows you to freely reorder the string.
        // ----> strings should have same unique letters
        //Operation 2 allows you to freely reassign the letters' frequencies.
        // ----> sorted frequencies are equal
        if(word1.size()!=word2.size())  return false;

        vector<int> freq1(26),freq2(26);
        set<char> uniq1,uniq2;
        for(int i=0;i<word1.size();i++){
            char c1=word1[i],c2=word2[i];

            uniq1.insert(c1);
            freq1[c1-'a']++;

            uniq2.insert(c2);
            freq2[c2-'a']++;
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        
        return uniq1==uniq2 && freq1==freq2;
    }
};
