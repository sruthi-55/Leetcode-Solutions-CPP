class Solution {
public:
    bool cannotColor(int i,int col,vector<vector<int>> &graph,vector<int>& color){
        color[i]=col;
        for(auto nei:graph[i]){
            if(color[nei]==-1){
                if(cannotColor(nei,!col,graph,color)) return true;
            }
            else if(color[nei]==col)    return true;
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(cannotColor(i,0,graph,color))    return false;
            }
        }
        return true;
    }
};
