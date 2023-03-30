class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        int i = num.size()-1, carry = 0;
        while((k||carry) && i>=0)
        {
            int sum = num[i] + (k%10) + carry;
            int r = sum%10;
            carry = sum/10;
            num[i--] = r;
            k/=10;
        }
        while (k||carry)
        {
            int sum = (k%10) + carry;
            int r = sum%10;
            carry = sum/10;
            num.insert(num.begin(), r);
            k/=10;
        }
        return num;
    }
};