class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wordLen=words[0].size();
        int noOfWords=words.size();
        int totalLen= noOfWords*wordLen;

        if(totalLen >s.size())  return ans;

        unordered_map<string,int> count;
        for(auto word:words)    count[word]++;

        int j=0;
        for(int i=0;i<wordLen;i++){
            unordered_map<string,int> m;
            int left=i;
            for(int j=i;j<=s.size()-wordLen;j+=wordLen){
                string newWord= s.substr(j,wordLen);

                if(count.find(newWord)!=count.end()){
                    m[newWord]++;
                    //sliding window
                    while(m[newWord]>count[newWord]){
                        m[s.substr(left,wordLen)]--;
                        left+=wordLen;
                    }
                    if(j+wordLen-left==totalLen){
                        ans.push_back(left);
                        m[s.substr(left,wordLen)]--;
                        left+=wordLen;
                    }  
                }
                else{
                    m.clear();
                    left=j+wordLen;
                }
            }
        }
        return ans;
    }
};
