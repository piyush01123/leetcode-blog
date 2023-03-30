class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int currA = capacityA, currB = capacityB, n = plants.size();
        int i=0, j=n-1, res = 0;
        while(i<j)
        {
            if(currA<plants[i])
            {
                currA = capacityA;
                res++;
            }
            if(currB<plants[j])
            {
                currB = capacityB;
                res++;
            }
            currA = currA-plants[i];
            currB = currB-plants[j];
            i++;
            j--;
        }
        if (i==j)
        {
            if (max(currA,currB)<plants[i]) res++;
        }
        return res;
    }
};