class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int> visited;
        visited[{0,0}]=1;
        int curX=0,curY=0;
        for(int i=0;i<path.size();i++){
            if(path[i]=='N')    curY+=1;
            else if(path[i]=='S')   curY-=1;
            else if(path[i]=='E')   curX+=1;
            else    curX-=1;
            if(visited.find({curX,curY})!=visited.end())    return true;
            visited[{curX,curY}]=1;
        }
        return false;
    }
};
