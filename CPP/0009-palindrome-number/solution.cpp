class Solution {
public:
    bool isPalindrome(int x) {
        string revNum = to_string(x);
        string original = revNum;
        reverse(revNum.begin(),revNum.end());
        return original == revNum;
    }
};
