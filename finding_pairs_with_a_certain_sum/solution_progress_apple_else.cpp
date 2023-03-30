class FindSumPairs {
    vector<int> arr1, arr2;
    unordered_map<int,int> a2freq;

    public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        arr1 = nums1;
        arr2 = nums2;
        for (int n: nums2) a2freq[n] += 1;
    }
    
    void add(int index, int val) 
    {
        int prev = arr2[index];
        arr2[index] += val;
        int curr = arr2[index];
        a2freq[prev] -= 1;
        a2freq[curr] += 1;
    }
    
    int count(int tot) 
    {
        int res = 0;
        for (int a: arr1)
            res += a2freq[tot-a];
        return res;
    }

    // int count_equal_lengths(int tot) 
    // {
    //    int res = 0;
    //     int n1=a1keys.size(), n2=a2keys.size(),ctr1=0,ctr2=0;
    //     set<int>::iterator it1=a1keys.begin(), it2=a2keys.end(); --it2;
    //     while (ctr1<n1 && ctr2 <n2)
    //     {
    //         int a = *it1, b = *it2;
    //         if (a+b == tot)
    //         {
    //             ++it1; --it2; ctr1++; ctr2++;
    //             res += (a1freq[a]*a2freq[b]);
    //         }
    //         if (a+b < tot) {++it1; ctr1++;}
    //         if (a+b > tot) {--it2; ctr2++;}
    //     }
    //     return res;
    // }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */