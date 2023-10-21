class Solution {
    vector<int> digits;
    vector<int> F;
public:
    void permute(int n, int k, int pos=0) {
        if (n==0) return;
        int cur = k / F[n-1];
        int rem = k % F[n-1];
        swap(digits[pos+cur], digits[pos]);
        sort(digits.begin()+pos+1, digits.end());
        permute(n-1, rem, pos+1);
    }
    string getPermutation(int n, int k)
    {
        int p=1; F.push_back(1);
        for(int i=1; i<=n; i++) 
        {
            digits.push_back(i); 
            p*=i; 
            F.push_back(p);
        }
        permute(n,k-1);
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