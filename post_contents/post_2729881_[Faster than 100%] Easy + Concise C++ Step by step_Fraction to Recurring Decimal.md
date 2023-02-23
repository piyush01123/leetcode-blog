Here is the code without taking care of the recurring decimal (Will give you WA for case `nr=1,dr=3` but still it is useful to understand):
```
string fractionToDecimal(int nr, int dr) 
{
	if (nr==0) return "0";
	string res = "";
	if ((nr<0)^(dr<0)) res += "-";
	nr = abs(nr), dr=abs(dr);
	res += to_string(nr/dr);
	int rem = nr%dr;
	if (rem==0) return res;
	res += ".";
	while (rem>0)
	{
		rem *= 10;
		res += to_string(rem/dr);
		rem %= dr;
	}
	return res;
}
```

Now we add the recurring decimal part. We will use a hash map to store the position of each decimal digit. If we have seen it earlier than we are due to repeat, hence we break and return.

There are some gotchas you need to take care of.
- `abs(INT_MIN)` is `INT_MIN` as defined in `cstdlib.h`.
- Hence we use `long long int` for our nr and dr.
- Also use `long long int` for the remainder.
- You got to be careful about the insertion position of the starting open paranthesis `(`.

Final code:
```
string fractionToDecimal(long long nr, long long dr) 
{
    if (nr==0) return "0";
    string res = "";
    if ((nr<0)^(dr<0)) res += "-";
    nr = abs(nr), dr=abs(dr);
    res += to_string(nr/dr);
    long long rem = nr%dr;
    if (rem==0) return res;
    res += ".";
    unordered_map<int,int> decimal;
    while (rem>0 && decimal.count(rem)==0)
    {
        decimal[rem] = res.length();
        rem *= 10;
        res += to_string(rem/dr);
        rem %= dr;
    }
    if (rem>0)
    {
        res.insert(decimal[rem], "(");
        res += ")";
    }
    return res;
}
```

**Result:**
```
Success
Details
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fraction to Recurring Decimal.
Memory Usage: 6.3 MB, less than 74.68% of C++ online submissions for Fraction to Recurring Decimal.
```