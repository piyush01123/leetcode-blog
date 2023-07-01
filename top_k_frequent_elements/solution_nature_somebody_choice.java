class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int[] res = new int[k];
        HashMap<Integer,Integer> H = new HashMap<Integer,Integer>();
        for(int num: nums) if (H.containsKey(num)) H.put(num, H.get(num)+1); else H.put(num,1);
        HashMap<Integer,List<Integer>> F = new HashMap<Integer,List<Integer>>();
        PriorityQueue<Integer> freq = new PriorityQueue<Integer>();
        for (Map.Entry<Integer,Integer> entry: H.entrySet())
        {
            int f = entry.getValue();
            if (!F.containsKey(f))
            {
                F.put(f, new ArrayList<Integer>());
                freq.offer(f);
                if (freq.size()>k) freq.remove();
            }
            List<Integer> curKeys = F.get(f);
            curKeys.add(entry.getKey());
            F.put(f, curKeys);
        }
        int ctr=0;
        PriorityQueue<Integer> freq2 = new PriorityQueue<Integer>(Collections.reverseOrder());
        while(!freq.isEmpty()) freq2.offer(freq.poll());
        while(!freq2.isEmpty())
        {
            int f = freq2.poll();
            for (int key: F.get(f))
            {
                res[ctr++] = key;
                if (ctr==k) return res;
            }
        }
        return res;
    }
}