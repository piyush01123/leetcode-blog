void swap_ints(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
class Solution {
private:
    vector<int> nums_orig;
public:
    Solution(vector<int>& nums) {
        nums_orig = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_orig;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums = nums_orig;
        for (int i=nums.size()-1; i>0; i--){
            int j = rand()%(i+1);
            swap_ints(&nums[i], &nums[j]);
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */