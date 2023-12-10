class SeatManager 
{
    priority_queue<int,vector<int>,greater<int>> avail;
    int cur;
public:
    SeatManager(int n) 
    {
        cur = 1;
    }
    
    int reserve() 
    {
        if (avail.empty() || avail.top()>cur) return cur++;
        int seat_number = avail.top();
        avail.pop();
        return seat_number;
    }
    
    void unreserve(int seatNumber) 
    {
        avail.push(seatNumber);        
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */