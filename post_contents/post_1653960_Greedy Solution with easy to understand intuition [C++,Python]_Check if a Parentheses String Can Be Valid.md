Suppose there were no `locked` string and we need to only check if a given string is valid or not then we can do the following logic for forward:
```
int bal=0, n=s.size();
for (int i=0; i<n; i++)
{
	if (s[i]=="(") bal++;
	else bal--;
	if (bal<0) return false;
}
return true;
```
Above code checks orphan `)`. Now the following for backward  checks orphan `(`:
```
int bal = 0;
for (int i=n-1; i>=0; i--)
{
	if (s[i]==")") bal++;
	else bal--;
	if (bal<0) return false;
}
return true;
```

Together we can use both to check valid string:
```
bool isValid(string s) {
	if (s.size()%2==1) return false;
	int bal=0, n=s.size();
	for (int i=0; i<n; i++)
	{
		if (s[i]=="(" ) bal++;
		else bal--;
		if (bal<0) return false;
	}
	bal = 0;
	for (int i=n-1; i>=0; i--)
	{
		if (s[i]==")") bal++;
		else bal--;
		if (bal<0) return false;
	}
	return true;
}
```

Now to solve our `canBeValid` problem we just need to add an extra condition as OR to allow one of the non-locked bracket to be inverted.
C++:
```
class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size()%2==1) return false;
        int bal=0, n=s.size();
        for (int i=0; i<n; i++)
        {
            if (s[i]=="(" || locked[i]=="0") bal++;
            else bal--;
            if (bal<0) return false;
        }
        bal = 0;
        for (int i=n-1; i>=0; i--)
        {
            if (s[i]==")" || locked[i]=="0") bal++;
            else bal--;
            if (bal<0) return false;
        }
        return true;
    }
};
```
Python:
```
class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        if len(s)%2==1: return False
        bal = 0
        for ch, lock in zip(s, locked):
            if lock == "0" or ch == "(": bal += 1
            else: bal -= 1
            if bal < 0: return False 
        bal = 0
        for ch, lock in zip(reversed(s), reversed(locked)): 
            if lock == "0" or ch == ")": bal += 1
            else: bal -= 1
            if bal < 0: return False
        return True
```