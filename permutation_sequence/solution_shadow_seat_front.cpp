class Solution {
public:
    string getPermutation(int n, int k)
    {
        vector<int> digits(n), F(n+1,1);
        int p=1, pos=0; k--;
        for(int i=1; i<=n; i++){digits[i-1]=i; F[i]=i*F[i-1];}
        while(n--)
        {
            int cur = k / F[n];
            k %= F[n];
            swap(digits[pos+cur], digits[pos]);
            sort(digits.begin() + (++pos), digits.end());
        }
        string res="";
        for (int digit: digits) res+=to_string(digit);
        return res;
    }
};


/*
1,2,3,4,5
5,87

86/24=3
4,  1,2,3,5
14/6=2
4,3,  1,2,5
2/2=1
4,3,2,  1,5
0/1=0
4,3,2,1,  5


5,120
119/24=4
5,1,2,3,4
23/6=3
5,4,1,2,3
5/2=2
5,4,3,1,2
1/1=1
5,4,3,2,1

*/