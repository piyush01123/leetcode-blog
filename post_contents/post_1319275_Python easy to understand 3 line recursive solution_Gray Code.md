We see the pattern:
```
1: [0,1]
2: [00,01,11,10]
3: [000,001,011,010,110,111,101,100]
```
Notice the following recursive relation:
```
grayCode(n) = [grayCode(n-1), new_part]
```
`new_part` consists of `1` added to the left of each item in reversed sequence of `grayCode(n-1)`.

This leads us to the following code:
```python
class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n==1: return [0,1]
        prev = self.grayCode(n-1)
        return prev + [2**(n-1)+i for i in prev[::-1]]
```
Time complexity: `O(n)`.