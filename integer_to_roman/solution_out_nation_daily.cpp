class Solution {
public:
    string repeat(int x, string s)
    {
        string res="";
        while (x-- > 0) res+=s;
        return res;
    }
    string intToRoman(int num) 
    {
        vector<int> values {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> romans {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res=""; 
        int i=0;
        while (num > 0)
        {
            while (values[i]>num) i++;
            res.insert(res.length(), repeat(num/values[i], romans[i]));
            num %= values[i];
        }
        return res;
    }
};