class Solution {
public:
    string intToRoman(int num) 
    {
        vector<int> values {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> romans {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res="";
        while (num > 0)
        {
            int i=0;
            while (values[i]>num) i++;
            num -= values[i];
            res += romans[i];
            cout << num << endl;
        }
        return res;
    }
};