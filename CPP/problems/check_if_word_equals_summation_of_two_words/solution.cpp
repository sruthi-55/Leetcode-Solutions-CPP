class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        string first,second,total;
        for(char c:firstWord)
            first+=to_string(c-'a');
        for(char c:secondWord)
            second+=to_string(c-'a');
        for(char c:targetWord)
            total+=to_string(c-'a');
        return stoi(first)+stoi(second)==stoi(total);
    }
};