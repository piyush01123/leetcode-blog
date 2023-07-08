class UndergroundSystem 
{
    unordered_map<int, pair<string,int>> locations;
    unordered_map<string, pair<double,int>> times;
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) 
    {
        locations[id] = {stationName,t};        
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        auto [location, time] = locations[id];
        locations[id] = {stationName,t};
        string src_dst = location + "-->" + stationName;
        double total_time = 0;
        int ctr = 0;
        if (times.count(src_dst))
        {
            double prev_avg = times[src_dst].first;
            ctr = times[src_dst].second;
            total_time = prev_avg * ctr;
        }
        ctr++;
        // cout << id << ',' << stationName << ',' << t << ',' << total_time << ',' << ctr << ',' << t << endl;
        times[src_dst] = {(total_time+(t-time))/ctr, ctr};
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        return times[startStation + "-->" + endStation].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */