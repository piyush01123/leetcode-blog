class SummaryRanges {
        set<int> nums;
        vector<vector<int>> ranges;
public:
    SummaryRanges() {
    }
    
    void addNum(int value) {
        auto it = upper_bound(nums.begin(),nums.end(),value);
        nums.insert(it, value);
        ranges = {};
        it = nums.begin();
        ranges.push_back({*it, *it});
        it++;
        for (; it!=nums.end(); it++)
        {
            if (*it==ranges.back()[1]+1) ranges.back()[1]++;
            else ranges.push_back({*it,*it});
        }
        return;
    }
    
    vector<vector<int>> getIntervals() {
        return ranges;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */