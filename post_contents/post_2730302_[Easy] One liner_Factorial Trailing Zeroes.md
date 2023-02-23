You should notice that the number of zeros is bounded by the number of factors of 5 and its powers because 2 will have always more. So we just count the number of factors of each power of 5 from 1 to n using a simple divide operation.
```
int trailingZeroes(int n) 
{
    return n/3125 + n/625 + n/125 + n/25 + n/5;
}
```