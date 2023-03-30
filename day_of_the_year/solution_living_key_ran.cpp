class Solution {
public:
    int dayOfYear(string date) {
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        string yyyy = string(date.begin(),date.begin()+4);
        string mm = string(date.begin()+5,date.begin()+7);
        string dd = string(date.begin()+8, date.end());
        int D=stoi(dd), M=stoi(mm), Y=stoi(yyyy);
        if ((Y%4==0 && Y%100>0) || (Y%400==0)) days[1]=29;
        int ctr=0;
        for (int m=0;m<M-1;m++) ctr+=days[m];
        ctr+=D;
        return ctr;
    }
};