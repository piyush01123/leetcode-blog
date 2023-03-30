class Solution {
public:
    int numSquares(int n) {
        vector<int> A{0,1};
        for (int i=2; i<=n; i++){
            int curr_min = INT_MAX;
            for (int j=1; j*j<=i; j++){
                int k = j*j;
                if (k==i){
                    curr_min = 1;
                    break;
                }
                curr_min = min(curr_min, A[k] + A[i-k]);
            }
            A.push_back(curr_min);
        }
        return A.back();
    }
};