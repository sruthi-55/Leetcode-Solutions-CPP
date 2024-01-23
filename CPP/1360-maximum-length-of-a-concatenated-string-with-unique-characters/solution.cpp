class Solution {
public:
    bool hasCommon(string &s1, string& s2) {
        int arr[26] = {0};
        
        for(char &ch : s1) {
            arr[ch-'a']++;
        }
        
        for(char &ch : s2) {
            arr[ch-'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(arr[i] > 1) {
                return true; //has common letter
            }
        }
        return false;
    }
    
    int solve(int idx, vector<string>& arr, string temp, int n) {
        if(idx >= n)
            return temp.length();
        
        int include = 0;
        int exclude = 0;
        if(hasCommon(temp, arr[idx])) {
            exclude = solve(idx+1, arr, temp, n);
        } else {
            exclude = solve(idx+1, arr, temp, n);
            temp += arr[idx];
            include = solve(idx+1, arr, temp, n);
        }
        
        return max(include, exclude);
    }
    
    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();
        
        return solve(0, arr, temp, n);
        
    }
};
