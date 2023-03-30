class Solution {
public:
    unordered_map<int,string> H;
    int ctr = 0;
    string base_url = "http://tiny.io/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        H[ctr] = longUrl;
        return base_url + to_string(ctr++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string nstr = string(shortUrl.begin()+15,shortUrl.end());
        int n = stoi(nstr);
        return H[n];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));