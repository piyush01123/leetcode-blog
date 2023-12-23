class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> lineWords, res;
        int lineLength=0;
        for(string word: words)
        {
            if (lineLength + word.length() > maxWidth)
            {
                lineLength = 0;
                res.push_back(createLine(lineWords, maxWidth, (lineWords.size()==1)));
                lineWords = {};
            }
            lineWords.push_back(word);
            lineLength += word.length()+1;
        }
        res.push_back(createLine(lineWords, maxWidth, true));
        return res;
    }
    string createLine(vector<string>&words, int maxWidth, bool vanilla)
    {
        // for(string w: words)cout<<w<<' ';cout<<endl; cout<<vanilla<<endl;
        if (vanilla)
        {
            string res = "";
            for(string w: words) res += w+" ";
            res.pop_back();
            res += string(maxWidth-res.length(), ' ');
            // cout << "RES^" << res << "$" << endl;
            return res;
        }
        int width = 0; for(string w: words) width += w.length();
        int spaces = (maxWidth-width) / (words.size()-1);
        int extras = (maxWidth-width) % (words.size()-1);
        string res = "";
        for(int i=0; i<extras; i++)
        {
            res += words[i]+" ";
            res += string(spaces, ' ');
        }
        for(int i=extras; i<words.size()-1; i++)
        {
            res += words[i];
            res += string(spaces, ' ');
        }
        res += words.back();
        // cout << "RES^" << res << "$" << endl;
        return res;
    }
};