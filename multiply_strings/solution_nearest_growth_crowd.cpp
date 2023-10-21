class Solution {
public:
    string add(string a, string b)
    {
        // cout << "add:"<<a<<','<<b<<endl;
        if (!a.length()) return b;
        if (!b.length()) return a;
        string res = "";
        int carry = 0;
        while(a.length() && b.length())
        {
            int cur = (a.back()-'0')+(b.back()-'0')+carry;
            res += to_string(cur%10);
            carry = cur/10;
            a.pop_back();
            b.pop_back();
        }
        while(a.length())
        {
            int cur = (a.back()-'0')+carry;
            res += to_string(cur%10);
            carry = cur/10;
            a.pop_back();
        }
        while(b.length())
        {
            int cur = (b.back()-'0')+carry;
            res += to_string(cur%10);
            carry = cur/10;
            b.pop_back();
        }
        if (carry) res += to_string(carry);
        reverse(res.begin(),res.end());
        // cout<<"addRes:"<<res<<endl;
        return res;
    }
    string digitMul(int a, string num)
    {
        // cout << "digitMul "<<a<<','<<num<<endl;
        string res = "";
        int carry = 0;
        for (int i=num.size()-1; i>=0; i--)
        {
            int cur = a * (num[i]-'0') + carry;
            res.push_back('0' + (cur%10));
            carry = (cur/10);
        }
        if (carry) res.push_back('0'+carry);
        reverse(res.begin(),res.end());
        // cout << "mulRes:" << res << endl;
        return res;
    }
    string multiply(string num1, string num2) 
    {
        if (num1=="0" || num2=="0") return "0";
        string result = "";
        for (int i=0; i<num1.length(); i++)
        {
            string product = digitMul(num1[i]-'0', num2);
            product += string(num1.length()-i-1, '0');
            // cout << "prod:"<<product<<endl;
            result = add(result, product);
            // cout << "curResult:"<<result<<endl;
        }
        return result;
    }
};


/*
abcdefg
pqr

*/