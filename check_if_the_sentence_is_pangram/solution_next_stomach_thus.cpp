class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.length()<26) return false;
        vector<bool> presence(26, false);
        for (char ch: sentence) presence[ch-'a']=true;
        for (bool b: presence) if (!b) return false;
        return true;
    }
};