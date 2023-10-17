class Solution {
public:
    int countNodes(int root,vector<int>& l, vector<int>& r){
        if(root==-1)    return 0;
        return 1+ countNodes(l[root],l,r) + countNodes(r[root],l,r);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n,0);
        for(int i=0;i<leftChild.size();i++){
            if(leftChild[i]!=-1)    inDegree[leftChild[i]]++;
            if(rightChild[i]!=-1)    inDegree[rightChild[i]]++;
        }
        int root = -1;
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]>1)   return false;
            if(inDegree[i]==0){
                if(root==-1)    root=i;
                else    return false;
            } 
        }
        if(root==-1) return false;
        return countNodes(root,leftChild,rightChild)==n;
    }
};
