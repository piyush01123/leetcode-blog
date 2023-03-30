class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        int c3=0, c5=0;
        for (int i=1; i<=n; i++)
        {
            string s; bool b=false;
            c3++; c5++;
            if (c3==3) {c3=0; b=true; s+="Fizz";}
            if (c5==5) {c5=0; b=true;s+="Buzz";}
            if (!b) s=to_string(i);
            res.push_back(s);
        }
        return res;
    }
};