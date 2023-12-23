class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int candidate_A, candidate_B, count_A=0, count_B=0;
        for (int n: nums)
        {
            if (n==candidate_A) count_A++;
            else if (n==candidate_B) count_B++;
            else if (count_A==0){candidate_A=n; count_A=1;}
            else if (count_B==0){candidate_B=n; count_B=1;}
            else {count_A--; count_B--;}
        }
        vector<int>res;
        if (count(nums.begin(),nums.end(),candidate_A)>nums.size()/3) 
            res.push_back(candidate_A);
        if (count(nums.begin(),nums.end(),candidate_B)>nums.size()/3) 
            res.push_back(candidate_B);
        return res;
    }
};