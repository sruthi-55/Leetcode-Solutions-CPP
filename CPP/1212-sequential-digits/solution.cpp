class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string s="123456789";
        for(int len=2;len<=s.length();len++){
            for(int startI=0; startI<=s.length()-len; startI++){
                string temp = s.substr(startI,len);
                int num = stoi(temp);
                if(num>=low && num<=high)   res.push_back(num);
            }
        }
        return res;
    }
};
