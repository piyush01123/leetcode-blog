class Solution {
public:
    int getWinner(vector<int>& arr, int k) 
    {
        if (k>=arr.size()-1) return *max_element(arr.begin(),arr.end());
        vector<int> vec;
        for (int i=0; i<arr.size(); i++)
        {
            // cout <<'i'<<i<<endl;
            while(!vec.empty() && vec.front()<arr[i]) vec.pop_back();
            vec.push_back(arr[i]);
            // cout<<'v'<<vec.size()<<'f'<<vec.front()<<endl;
            if (i==k && vec.size()==k+1) return vec.front();
            if (vec.size()==k && vec.front()!=arr[0]) return vec.front();
        }
        return *max_element(arr.begin(),arr.end());
    }
};