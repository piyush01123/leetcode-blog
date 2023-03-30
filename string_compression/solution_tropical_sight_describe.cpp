class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int n=chars.size(), i=0;
        while(i<n)
        {
            int j=i;
            while(j<n && chars[j]==chars[i]) j++;
            chars.push_back(chars[i]);
            if (j-i>1) for (char ch: to_string(j-i)) chars.push_back(ch);
            i = j;
        }
        chars = vector<char>(chars.begin()+n, chars.end());
        return chars.size();
    }
};