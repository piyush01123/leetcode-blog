class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i=digits.size()-1; i>=0; --i)
        {
            int temp = (carry+digits[i]);
            digits[i] = temp%10;
            carry = temp/10;
        }
        if (carry>0) digits.insert(digits.begin(), carry);
        return digits;
    }
};