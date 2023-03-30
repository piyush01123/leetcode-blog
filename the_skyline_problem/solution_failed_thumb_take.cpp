template<typename T>
class my_priority_queue : public priority_queue<T,vector<T>>
{
    public: 
    bool remove(const T &item);
};

template<typename T>
bool my_priority_queue<T>::remove(const T &item)
{
    auto it = find(this->c.begin(), this->c.end(), item);
    if (it==this->c.end()) return false;
    if (it==this->c.begin()) this->pop();
    else 
    {
        this->c.erase(it);
        make_heap(this->c.begin(),this->c.end(),this->comp);
    }
    return true;
}

bool cmp(pair<int,int>a, pair<int,int>b)
{
    if (a.first != b.first) return a.first<b.first;
    return a.second<b.second;
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<pair<int,int>> data;
        for (auto b: buildings) 
        {
            int s=b[0], e=b[1], h=b[2];
            data.push_back({s, -h});
            data.push_back({e, +h});
        }
        sort(data.begin(),data.end());
        multiset<int> pq;
        int prev = 0;
        pq.insert(0);
        vector<vector<int>> res;
        for (auto point: data)
        {
            if (point.second<0) pq.insert(-point.second);
            else pq.erase(pq.find(point.second));
            int cur = *pq.rbegin();
            if (cur!=prev) 
            {
                res.push_back({point.first, cur});
                prev = cur;
            }
        }
        return res;
    }
};