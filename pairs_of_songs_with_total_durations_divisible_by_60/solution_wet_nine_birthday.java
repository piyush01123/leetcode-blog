class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int comps[] = new int[60];
        Arrays.fill(comps,0);
        int res=0;
        for (int t: time)
        {
            res += comps[t%60];
            comps[(60-(t%60))%60]++;
        }
        return res;        
    }
}