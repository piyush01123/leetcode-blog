Make sure to take care of [leap year rule](https://www.mathsisfun.com/leap-years.html).
Examples of leap years: 1992,1996,2000,2004,..,2096,2104

# Code
```
class Solution {
public:
    int dayOfYear(string date) {
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int Y=stoi(date.substr(0,4)), M=stoi(date.substr(5,2)), D=stoi(date.substr(8,2));
        if ((Y%4==0 && Y%100>0) || (Y%400==0)) days[1]=29;
        int ctr=0;
        for (int m=0;m<M-1;m++) ctr+=days[m];
        ctr+=D;
        return ctr;
    }
};
```