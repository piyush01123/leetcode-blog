class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) 
    {
        int n = nums1.length;
        List<Integer> indices = new ArrayList<Integer>();
        for(int i=0;i<n;i++)indices.add(i);
        Collections.sort(indices, (i,j)->nums2[j]-nums2[i]);
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        long curSum=0, res=0;
        for (int i=0; i<n; i++)
        {
            int index = indices.get(i);
            int curMin = nums2[index];
            curSum += nums1[index];
            pq.add(nums1[index]);
            if (pq.size()<k) continue;
            if (pq.size()>k) curSum-=pq.poll();
            res = Math.max(res, curSum*curMin);
        }
        return res;
    }
}