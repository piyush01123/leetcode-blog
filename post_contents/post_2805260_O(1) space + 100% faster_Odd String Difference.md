```
class Solution {
public:
    string oddString(vector<string>& words) 
    {
        int m=words.size(), n=words[0].length();
        for(int j=1; j<n; j++)
        {
            int dA = words[0][j]-words[0][j-1];
            int dB = words[1][j]-words[1][j-1];
            if (dA!=dB)
            {
                int dC = words[2][j]-words[2][j-1];
                return ((dC==dA) ? words[1] : words[0]);
            }
            // dA==dB
            for (int i=2; i<m; i++)
            {
                int diff = words[i][j]-words[i][j-1];
                if (diff!=dA) return words[i];
            }
        }
        return "";
    }
};
```