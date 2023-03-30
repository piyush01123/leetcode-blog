class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 2(F+A)=F+nC+A==>F+A=nC. Then (F+A+F,F)=(nC+F,F)
        int hare=nums[0], tortoise=nums[0];
        while(1)
        {
            tortoise=nums[tortoise];
            hare=nums[nums[hare]];
            if (tortoise==hare) break;
        }
        tortoise=nums[0];
        while(tortoise!=hare)
        {
            tortoise=nums[tortoise];
            hare=nums[hare];
        }
        return hare;
    }
};