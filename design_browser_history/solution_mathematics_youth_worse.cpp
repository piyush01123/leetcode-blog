class BrowserHistory {
public:
    vector<string> history;
    int cur;
    BrowserHistory(string homepage) 
    {
        history.push_back(homepage);
        cur = 0;
    }
    
    void visit(string url) 
    {
        cur++;
        history = vector<string>(history.begin(), history.begin()+cur);
        history.push_back(url);
    }
    
    string back(int steps) 
    {
        cur -= steps;
        cur = max(cur, 0);
        return history[cur];
    }
    
    string forward(int steps) 
    {
        cur += steps;
        cur = min(cur, (int)history.size()-1);
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */