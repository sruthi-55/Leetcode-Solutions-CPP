class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n==1)    return 1;

        int writeInd = 0;
        char curChar = chars[0];
        int curCharCount = 1;

        for(int i=1;i<n;i++){
            if(chars[i]==curChar){
                curCharCount++;
            }
            else{
                chars[writeInd++] = curChar;
                if(curCharCount==1){
                    curChar = chars[i];
                    curCharCount = 1;
                    continue;
                }
                else{
                    string count = to_string(curCharCount);
                    for(auto c:count)
                        chars[writeInd++]=c;
                }
                curChar = chars[i];
                curCharCount = 1;
            }
        }
        if(curCharCount){
            chars[writeInd++] = curChar;
            if(curCharCount!=1){
                string count = to_string(curCharCount);
                for(auto c:count)
                    chars[writeInd++]=c;
            }
        }
        return writeInd;
    }
};
