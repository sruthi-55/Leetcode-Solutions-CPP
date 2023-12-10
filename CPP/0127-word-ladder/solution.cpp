class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> set(wordList.begin(),wordList.end());
        set.erase(beginWord);

        q.push({beginWord,1});
        while(!q.empty()){
            auto it = q.front();
            string word = it.first;
            int count = it.second;
            q.pop();
            if(word==endWord)   return count;
            
            for(int i=0;i<word.size();i++){
                string original=word;
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(set.find(word)!=set.end()){
                        q.push({word,count+1});
                        set.erase(word);
                    }
                }
                word=original;
            }
        }
        return 0;
    }
};
