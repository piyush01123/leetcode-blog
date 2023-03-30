class SeatManager {
    priority_queue<int,vector<int>,greater<int>> pq;
    int ctr=0;
public:
    SeatManager(int n) {
    }
    
    int reserve() {
        if (pq.size()==0) return ++ctr;
        int minAvailable = pq.top();
        pq.pop();
        return minAvailable;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */