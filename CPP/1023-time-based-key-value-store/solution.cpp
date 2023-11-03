class TimeMap {
public:
    static bool myComp(const pair<int,string> &a, const pair<int,string> &b) {
        return a.first < b.first;
    }
    unordered_map<string,vector<pair<int,string>>> map;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        //upperbound -1
        auto it= upper_bound(begin(map[key]),end(map[key]),make_pair(timestamp,""),myComp);
        return it == map[key].begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
