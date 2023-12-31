class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int> m;
        for(int i=0;i<s.size();i++){
            string str = "";
            for(int j=i;j<s.size();j++){
                str+=s[j];
                m[str]++;
            }
        }
        
        int ans=-1;
        for(auto e:m){
            string subStr=e.first;
            int len = subStr.size();
            int occur =e.second;
            
            unordered_set<char> set;
            for(char c:subStr)   set.insert(c);
            
            if((int)set.size()==1){
                if(occur >=3) ans=max(ans,len);
            }   
        }
        
        return ans;
        
    }
};
