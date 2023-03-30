class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num==1) return true;
        long long int low=1, high=num, mid;
        while(low<high)
        {
            mid=(low+high)/2;
            if (mid*mid==num) return true;
            if (mid*mid<num) low=++mid;
            if (mid*mid>num) high=--mid;
        }
        return mid*mid==num;
    }
};