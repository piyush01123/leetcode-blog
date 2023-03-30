class Solution {
public:
    bool valid(string wordA, string wordB, unordered_map<char,int>&H)
    {
        for(int j=0; j<wordA.length(); j++)
        {
            if (j==wordB.length()) return false;
            char chA = wordA[j], chB = wordB[j];
            if (H[chA]<H[chB]) return true;
            if (H[chA]>H[chB]) return false;
        }
        cout << "Never reach here" << endl;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) 
    {
        unordered_map<char,int>H;
        for(int i=0; i<26; i++) H[order[i]]=i;
        for(int i=0; i<words.size()-1; i++)
            if (!valid(words[i],words[i+1],H)) return false;
        return true;
    }
};