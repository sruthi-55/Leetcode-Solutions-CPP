class Solution {
public:
    vector<int> getDigits(int n){
        vector<int> digits;
        while(n!=0){
            int r = n%10;
            digits.push_back(r);
            n/=10;
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
    int compress(vector<char>& chars) {
        int lastWrite=0;

        char curChar=chars[0];
        int charCount=1;
        for(int i=1;i<chars.size();i++){
            if(chars[i]==curChar)   charCount++;
            else{
                chars[lastWrite] = curChar;
                lastWrite++;

                if(charCount==1){
                    curChar = chars[i];
                    charCount = 1;
                    continue;
                }
                else{
                    vector<int> digits = getDigits(charCount);
                    for(auto d:digits){
                        chars[lastWrite]='0'+d;
                        lastWrite++;
                    }
                    curChar = chars[i];
                    charCount = 1;
                }
            }
        }
        chars[lastWrite] = curChar;
        lastWrite++;
        if(charCount==1){
            //continue
        }
        else{
            vector<int> digits = getDigits(charCount);
            for(auto d:digits){
                chars[lastWrite]='0'+d;
                lastWrite++;
            }
        }

        return lastWrite;
    }
};
