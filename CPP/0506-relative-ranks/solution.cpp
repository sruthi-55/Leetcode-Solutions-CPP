class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> answer(score.size());
        unordered_map<int,int> mp;
        for(int i=0;i<score.size();i++){
            mp[score[i]]=i;
        }
        
        sort(score.begin(),score.end(),greater());
        int count=0;
        for(int i=0;i<score.size();i++){
            count++;
            if(i==0)    answer[mp[score[i]]] = "Gold Medal";
            else if(i==1)   answer[mp[score[i]]] = "Silver Medal";
            else if(i==2)   answer[mp[score[i]]] = "Bronze Medal";
            else if(count>3){
                answer[mp[score[i]]] = to_string(count);
            }
        }
        return answer;
    }
};
