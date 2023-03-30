class Solution {
public:
    bool isRobotBounded(string instructions) {
        int a=0,b=0,c=0;
        for(char ch: instructions)
        {
            if(ch=='G')
            {
                if(c%4==0)b++;
                if(c%4==1)a--;
                if(c%4==2)b--;
                if(c%4==3)a++;
            }
            if(ch=='L') c++;
            if(ch=='R') c+=3;
        }
        cout << a << ' ' << b << ' ' << c << endl;
        if(c%4==0 && (a!=0 || b!=0)) return false;
        return true;
    }
};