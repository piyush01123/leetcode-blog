```
class Solution {
public:
    unordered_map<int,string> int2url;
    unordered_map<string,int> url2int;
    string base_url = "http://tiny.io/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (url2int.find(longUrl)==url2int.end())
        {
            int ctr=url2int.size();
            url2int[longUrl] = ctr;
            int2url[ctr] = longUrl;
        }
        return base_url+to_string(url2int[longUrl]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string nstr = string(shortUrl.begin()+15,shortUrl.end());
        int n = stoi(nstr);
        return int2url[n];
    }
};
```