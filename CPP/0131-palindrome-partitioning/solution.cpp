class Solution {
public:
    bool isPalindrome(string& s,int l,int r) {
        while(l<r) {
            if(s[l]!=s[r])  return false;
            l++;    r--;
        }
        return true;
    }
    void getAllPalindromes(int i,string &s,vector<string> &path,vector<vector<string>> &res){
        if(i>=s.size()){
            res.push_back(path);
            return ;
        }

        for(int j=i;j<s.size();j++){
            if(isPalindrome(s,i,j)){
                path.push_back(s.substr(i, j-i+1));
                getAllPalindromes(j+1,s,path,res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        getAllPalindromes(0,s,path,res);
        return res;
    }
};
