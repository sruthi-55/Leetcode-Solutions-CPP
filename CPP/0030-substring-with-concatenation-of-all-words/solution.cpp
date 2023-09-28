class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int numOfWords = words.size();
        int wordLen = words[0].size();
        int totalLen = numOfWords * wordLen;

        if(totalLen > s.size()) return ans;
        unordered_map<string, int> count;
        for (auto word : words) count[word]++;

        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> seen;
            int left = i;
            //j traverses for each word 
            for (int j = i; j <= s.size() - wordLen; j += wordLen) {
                string newWord = s.substr(j, wordLen);

                if (count.find(newWord) != count.end()) {
                    //add newWord to seen
                    seen[newWord]++;
                    //if more occurences found than what is needed 
                    //shrink sliding window from left
                    if (seen[newWord] > count[newWord]) {
                        while (seen[newWord] > count[newWord]) {
                            seen[s.substr(left, wordLen)]--;
                            left += wordLen;
                        }
                    }
                    //if new window size is equal to totalLen
                    //it means all words are found
                    if (j + wordLen - left == totalLen) {
                        ans.push_back(left);
                        //check from next word
                        seen[s.substr(left, wordLen)]--;
                        left += wordLen;
                    }
                } 
                //if word not matched 
                else {
                    seen.clear();
                    //restart search from next word
                    left = j + wordLen;
                }
            }
        }
        return ans;
    }
};



