class Solution {
    int mod = 1e9+7;
public:
    int knightDialer(int n) 
    {
        vector<int> moves(10, 1);
        for (int i=1; i<n; i++)
        {
            vector<int> temp(10);
            temp[0] = moves[4]+moves[6];
            temp[1] = moves[6]+moves[8];
            temp[2] = moves[7]+moves[9];
            temp[3] = moves[4]+moves[8];
            temp[4] = (moves[0]+moves[3])%mod+moves[9];
            temp[5] = 0;
            temp[6] = (moves[0]+moves[1])%mod+moves[7];
            temp[7] = moves[2]+moves[6];
            temp[8] = moves[1]+moves[3];
            temp[9] = moves[2]+moves[4];
            moves = temp;
            for(int i=0; i<10; i++) moves[i] %= mod;
        }
        int res = 0;
        for(int i=0; i<10; i++) {res += moves[i]; res %= mod;}
        return res;
    }
};