class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size(),n2=version2.size();
        int i1=0,i2=0;
        for( ;i1<n1 && i2<n2; ){
            int j1=i1,j2=i2;
            while(j1<=n1 && version1[j1]!='.')     j1++;
            while(j2<=n2 && version2[j2]!='.')     j2++;

            int no1 = stoi(version1.substr(i1,j1-i1));
            int no2 = stoi(version2.substr(i2,j2-i2));
            if(no1>no2)    return 1;
            else if(no1<no2)    return -1;
            i1=j1+1;    i2=j2+1;
        }

        while(i1<n1){
            if(version1[i1]=='0' || version1[i1]=='.')  i1++;
            else    return 1;
        }
        while(i2<n2){
            if(version2[i2]=='0' || version2[i2]=='.')  i2++;
            else    return -1;
        }
        return 0;
    }
};
