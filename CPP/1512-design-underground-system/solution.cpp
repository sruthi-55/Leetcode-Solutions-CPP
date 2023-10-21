class UndergroundSystem {
public:
    //{id,{startS,startT}}
    unordered_map<int,pair<string,int>> chInMap;
    //{journey,{totalT,custCount}}
    unordered_map<string,pair<int,int>> journeyMap;

    UndergroundSystem() {    
        
    }
    
    void checkIn(int id, string stationName, int t) {
        chInMap[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int startT = chInMap[id].second;
        int endT = t;
        string journey = chInMap[id].first + "_" + stationName;
        journeyMap[journey].first+= (endT-startT);
        journeyMap[journey].second++;

        chInMap.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string journey = startStation+"_"+endStation;
        auto travelInfo = journeyMap[journey];
        return (double)travelInfo.first/travelInfo.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
