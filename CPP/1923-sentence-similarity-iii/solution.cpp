class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        int n1=s1.length(),n2=s2.length();

        //put words of s1 and s2 into seperate vectors
        vector<string> v1,v2;
        for(int i=0;i<n1;){
            while(i<n1 && s1[i]==' ')   i++;
            int j=i;
            while(j<n1 && s1[j]!=' ')   j++;
            if(i>=n1)   break;
            v1.push_back(s1.substr(i,j-i));
            i=j;
        }
        for(int i=0;i<n2;){
            while(i<n2 && s2[i]==' ')   i++;
            int j=i;
            while(j<n2 && s2[j]!=' ')   j++;
            if(i>=n2)   break;
            v2.push_back(s2.substr(i,j-i));
            i=j;
        }
        
        int N1=v1.size(),N2=v2.size();
        //make sure s1 is smallest size
        if(N1>N2) return areSentencesSimilar(s2,s1);
        
        //match smaller string with prefix and suffix of the larger one
        int i=0;
        while(i< N1  && v1[i]==v2[i]) i++;
        while(i< N1 && v1[i]==v2[N2 - (N1 -i)]) i++;
        return i==N1;
    }
};
