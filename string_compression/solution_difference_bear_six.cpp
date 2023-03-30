class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int n=chars.size(), i=0;
        vector<char> vec;
        while(i<n)
        {
            int j=i;
            while(j<n && chars[j]==chars[i]) j++;
            vec.push_back(chars[i]);
            if(j-i>1 && j-i<10) vec.push_back('0'+(j-i));
            if (j-i>=10) for (char ch: to_string(j-i)) vec.push_back(ch);
            i = j;
        }
        chars = vec;
        return chars.size();
    }
};