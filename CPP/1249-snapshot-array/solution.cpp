class SnapshotArray {
public:
    int curSnapID=0;
    //{index: {snapID: value} }
    map<int,map<int,int>> snaps;
    SnapshotArray(int length) {
        for(int i=0;i<length;i++){
            map<int,int> mp;
            // mp[0]=0;
            snaps[i]=mp;
        }
    }
    
    void set(int index, int val) {
        snaps[index][curSnapID]=val;
    }
    
    int snap() {
        return curSnapID++;
    }

    int get(int ind, int snap_id) {
        auto it = snaps[ind].upper_bound(snap_id);
        if(it==snaps[ind].begin())  return 0;
        return snaps[ind][prev(it)->first];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
