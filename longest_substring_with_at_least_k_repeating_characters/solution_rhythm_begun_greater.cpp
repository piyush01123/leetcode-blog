class Solution {
public:
    pair<char,int> getLFC(string s)
    {
        unordered_map<char,int> H;
        for (char ch: s)
            H[ch]++;
        char minCh; int minFreq=INT_MAX;
        for (auto p: H)
        {
            char ch = p.first;
            int freq = p.second;
            if (freq<minFreq)
            {
                minCh = ch;
                minFreq = freq;
            }
        }
        return {minCh, minFreq};
    }
    
    // vector<string> split(string s, char ch)
    // {
    //     vector<string> vec;
    //     int i=0;
    //     while (i<s.length())
    //     {
    //         string curr = "";
    //         while (i<s.length() && s[i]!=ch) {curr+=ch;i++;}
    //         if (curr.length()>0) vec.push_back(curr);
    //         i++;
    //     }
    //     return vec;
    // }

    vector<string> split(string str, char del)
    {
        vector<string> vec;
        // declaring temp string to store the curr "word" upto del
          string temp = "";

          for(int i=0; i<(int)str.size(); i++){
            // If cur char is not del, then append it to the cur "word", otherwise
              // you have completed the word, print it, and start a new word.
             if(str[i] != del){
                temp += str[i];
            }
              else{
                vec.push_back(temp);
                  temp = "";
            }
        }

          vec.push_back(temp);
        return vec;
    }    

    void test1(string s)
    {
        auto lfcp = getLFC(s);
        cout << lfcp.first << lfcp.second <<endl;        
    }
    void test2(string s, char ch)
    {
        
    }
    void test()
    {
        test1("aaabb");
        test1("ababbc");
        test1("weitongweitng");
    }
    int longestSubstring(string s, int k) 
    {
        // test();
        if (k > s.length()) return 0;
        auto lfcp = getLFC(s);
        char lfc = lfcp.first;
        int lfcFreq = lfcp.second;
        if (lfcFreq >= k) return s.length();
        vector<string> splits = split(s, lfc);
        int currMax = 0;
        for (string split: splits)
        {
            int curr = longestSubstring(split, k);
            if (curr > currMax)
                currMax = curr;
        }
        return currMax;
    }
};