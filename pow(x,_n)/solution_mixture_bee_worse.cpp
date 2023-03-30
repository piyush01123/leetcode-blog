class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1) return 1;
        if (x==-1) return (n>0)?-1:1;
        if (n==-2147483648) return (x>1||x<-1)?0:((x>0)?DBL_MAX:DBL_MIN);
        if(n<0){x=1/x; n=-n;}
        int p=1;
        double res=x;
        while(p<n/2)
        {
            res*=res;
            p<<=1;
        }
        while(p<n)
        {
            res*=x;
            p+=1;
        }
        return res;
    }
};