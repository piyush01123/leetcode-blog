Logic is to start from right end towards left and till you see nine ,change to zero, Now if stopping point is -1 then this means input was of the form `999..9` so answer has to be `1000..0` and if stopping point is somewhere in the middle then we can just increment it like `...2999` becomes `...3000`.

```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int i = digits.size() - 1;
        while (i>=0 && digits[i]==9) 
        {
            digits[i]=0; 
            i--;
        }
        if (i==-1) digits.insert(digits.begin(), 1);
        else digits[i]++;
        return digits;
    }
};
```


We can also do it in the form of a standard addition. This method will also work if instead of 1, we need to add some other number. This uses the standard "Carry over" method of addition.
```
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
```