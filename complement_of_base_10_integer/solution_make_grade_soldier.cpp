class Solution {
public:
    int bitwiseComplement(int n) {
        int twosPower=1;
        for (int i=0; i<=32; i++) 
        {
            twosPower<<=1;
            if (twosPower>n) break;
        }
        return twosPower-n-1;
    }
};