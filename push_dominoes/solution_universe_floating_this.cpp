class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<pair<int,pair<char,int>>> nearest_left, nearest_right;
        int left_idx=-1;
        char left_ch='X';
        for (int i=0; i<n; i++)
        {
            if (dominoes[i]!='.')
            {
                left_idx = i;
                left_ch = dominoes[i];
            }
            if (dominoes[i]=='.')
            {
                // cout << i << ' ' << i-left_idx << left_ch << endl;
                nearest_left.push_back({i,{left_ch,i-left_idx}});
            }
        }
        // cout<<"REVERE"<<endl;
        int right_idx=n;
        char right_ch='X';
        for (int i=n-1; i>=0; i--)
        {
            if (dominoes[i]!='.')
            {
                right_idx = i;
                right_ch = dominoes[i];
            }
            if (dominoes[i]=='.')
            {
                // cout << i << ' ' << right_idx-i << right_ch << endl;
                nearest_right.push_back({i,{right_ch,right_idx-i}});
            }
        }
        reverse(nearest_right.begin(),nearest_right.end());
        // cout<<nearest_left.size() << ' ' << nearest_right.size() << endl;
        for (int i=0; i<nearest_left.size(); i++)
        {
            auto nl = nearest_left[i], nr = nearest_right[i];
            // cout << i << nl.first << nl.second.first << nl.second.second << nr.first << nr.second.first << nr.second.second << endl;
            int dom_idx = nl.first;
            auto nls = nl.second, nrs = nr.second;
            if (nls.first=='R' && nrs.first=='L')
            {
                if (nls.second<nrs.second) dominoes[dom_idx] = 'R';
                if (nrs.second<nls.second) dominoes[dom_idx] = 'L';
                continue;
            }
            if (nls.first=='R')
            {
                dominoes[dom_idx] = 'R';
                continue;
            }    
            if (nrs.first=='L') 
            {
                dominoes[dom_idx] = 'L';
                continue;
            }
        }
        return dominoes;
    }
};