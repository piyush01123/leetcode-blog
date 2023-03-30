class MedianFinder {
public:
    priority_queue<int> q1; //lower half is a max heap
    priority_queue<int, vector<int>, greater<int>> q2; // upper half is a min heap
    MedianFinder() {        
    }
    
    void addNum(int num) {
        if (q1.size()==0 || num < q1.top()) q1.push(num);
        else q2.push(num);
        if (q1.size() > q2.size()+1)
        {
            q2.push(q1.top());
            q1.pop();
        } else if (q2.size() > q1.size()+1)
        {
            q1.push(q2.top());
            q2.pop();
        }
    }
    
    double findMedian() {
        int n1=q1.size(), n2=q2.size();
        if (n1 > n2) return q1.top();
        else if (n2 > n1) return q2.top();
        else if (n1==n2) return .5 * (double)q1.top() + .5 * (double)q2.top();
        return -1;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */