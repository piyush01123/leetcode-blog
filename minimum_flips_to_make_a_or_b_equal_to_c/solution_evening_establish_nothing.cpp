#define count __builtin_popcount

class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        int flippers = ((a|b)^c);
        int bothones = (a&b);
        return count(flippers) + count(flippers & bothones);
    }
};