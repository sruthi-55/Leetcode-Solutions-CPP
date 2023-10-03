class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxLen=0;
        int n=answerKey.size();

        int left=0;
        //checking for window with T's
        int count=0;
        for(int j=0;j<n;j++){
            if(answerKey[j]=='F')   count++;
            //move sliding window to right
            while(count>k){
                if(answerKey[left]=='F')    count--;
                left++;
            }
            maxLen=max(maxLen,j-left+1);
        }

        //checking for window with F's
        left=0,count=0;
        for(int j=0;j<n;j++){
            if(answerKey[j]=='T')   count++;
            //move sliding window to right
            while(count>k){
                if(answerKey[left]=='T')    count--;
                left++;
            }
            maxLen=max(maxLen,j-left+1);
        }

        return maxLen;
    }
};
