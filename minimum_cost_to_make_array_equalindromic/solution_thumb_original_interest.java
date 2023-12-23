class Solution {
    public long minimumCost(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int middle = 0;
        if (n == 1) return 0;

        if (n % 2 != 0) {
            middle = nums[n / 2];
        } else {
            middle = (int)(nums[(n - 1) / 2] + nums[n / 2]) / 2;
        }

        long result = Long.MAX_VALUE;

        for (int r = middle - 10000; r <= middle + 10000; r++) {
            if (isPal(r) == false) continue;

            result = Math.min(result, calculatecost(nums, r));
        }

        return result;
    }


    public boolean isPal(int n) {
        int r, sum = 0, temp;
        temp = n;
        while (n > 0) {
            r = n % 10; //getting remainder  
            sum = (sum * 10) + r;
            n = n / 10;
        }
        return temp == sum;
    }

    public long calculatecost(int[] nums, int r) {
        long cost = 0;
        for (int n: nums) {
            cost += Math.abs(n - r);
        }
        return cost;
    }
}