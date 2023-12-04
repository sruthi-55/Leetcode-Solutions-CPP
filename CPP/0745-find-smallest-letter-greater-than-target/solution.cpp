class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        char ans=letters[0];
        int ind = upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(ind<n)   ans=letters[ind];
        return ans;
    }
};
