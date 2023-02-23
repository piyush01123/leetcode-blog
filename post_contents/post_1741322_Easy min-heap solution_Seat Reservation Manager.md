Algorithm:
- At the beginning keep increasing counter at each reservation
- When someone does unreserve, then store their seat number in a min heap
- For a new booking try to first book from the heap. If heap is empty then increase your counter and book at `seat_number=counter`.
```
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

```