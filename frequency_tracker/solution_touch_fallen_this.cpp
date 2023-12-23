class FrequencyTracker {
    unordered_map<int,int> Hfreq, HfreqInv;
public:
    FrequencyTracker() {}
    
    void add(int number) 
    {
        if (Hfreq.count(number) && Hfreq[number]>0)
        {
            int f = Hfreq[number];
            HfreqInv[f]--;
        }
        Hfreq[number]++;
        int f = Hfreq[number];
        HfreqInv[f]++;
    }
    
    void deleteOne(int number) 
    {
        if (Hfreq.count(number) && Hfreq[number]>0)
        {
            int f = Hfreq[number];
            HfreqInv[f]--;
        } else return;
        Hfreq[number]--;
        int f = Hfreq[number];
        HfreqInv[f]++;        
    }
    
    bool hasFrequency(int frequency) {
        return (HfreqInv.count(frequency) && HfreqInv[frequency]>0);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */