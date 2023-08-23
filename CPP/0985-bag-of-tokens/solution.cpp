class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        // tokens = 100,200,300,400
        // power  = 200
        // score  = 0
        int maxScore=0;
        int score=0;
        int l=0,h=tokens.size()-1;
        while(l<=h){
            if(power>=tokens[l]){
                power-=tokens[l++];
                score++;
                maxScore=max(maxScore,score);
            }  
            else if(score>0)   power+=tokens[h--],score--;
            else    l++;
        }
        return maxScore;
    }
};
