After little bit of experimenting on paper, one can realize that the only situation that it does not land up at origin is if we do not end up on origin after one round and are also facing north.
The other two cases are:
- Ending up on origin: Obviously it is `true`
- Not ending up on origin but facing South/East/West: This is also true because after 2 rounds(South) or 4 rounds(East/West), we will again land at origin.

Now for implementation, we will use three variables:
- `a` for x-coordinate
- `b` for y-coordinate
- `c` for direction

All 3 are integers. One important thing to notice is that we can use `c` variable for direction as follows:
- If you see "L",  increment c by 1
- If you see "R", increment c by 3
- If you see "G", do not change c

Further we can check which direction we are facing:
- `c%4=0` means North
- `c%4=1` means West
- `c%4=2` means South
- `c%4=3` means East


Now the logic is that:
- If you see G, find out which direction you are facing and modify the coordinates accordingly. This will change either a or b.
- If you see L or R, change the variable c as per rule given above. Variables a and b do not change in this case.

```
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int a=0,b=0,c=0;
        for(char ch: instructions)
        {
            if(ch=="G")
            {
                if(c%4==0)b++;
                if(c%4==1)a--;
                if(c%4==2)b--;
                if(c%4==3)a++;
            }
            if(ch=="L") c++;
            if(ch=="R") c+=3;
        }
        cout << a << " " << b << " " << c << endl;
        if(c%4==0 && (a!=0 || b!=0)) return false;
        return true;
    }
};
```