class Solution {
public:
    int hammingDistance(int x, int y) {
        int ctr = 0;
        while (x>0 and y>0){
            if ((x%2) != (y%2)) ctr+=1;
            x/=2;
            y/=2;
        }
        while (x>0){
            if (x%2==1) ctr+=1;
            x/=2;
        }

        while (y>0){
            if (y%2==1) ctr+=1;
            y/=2;
        }
        return ctr;
    }
};