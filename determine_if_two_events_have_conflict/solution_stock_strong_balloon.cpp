class Solution {
public:
    int gethhmm(string &s)
    {
        string hh = s.substr(0,2), mm=s.substr(3,5);
        return stoi(hh)*60+stoi(mm);
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) 
    {
        int s1=gethhmm(event1[0]), e1=gethhmm(event1[1]), s2=gethhmm(event2[0]), e2=gethhmm(event2[1]);
        // cout<<s1<<','<<e1<<','<<s2<<','<<e2<<endl;
        return s2<=e1 && e2>=s1;
    }
};