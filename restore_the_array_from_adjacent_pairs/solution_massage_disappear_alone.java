class Solution {
    public int[] restoreArray(int[][] adjacentPairs) 
    {
        Map<Integer, List<Integer>> H = new HashMap();
        for (int[] pair: adjacentPairs)
        {
            H.computeIfAbsent(pair[0], k->new ArrayList()).add(pair[1]);
            H.computeIfAbsent(pair[1], k->new ArrayList()).add(pair[0]);
        }
        int start=-1, end=-1;
        for(var entry: H.entrySet())if(entry.getValue().size()==1)
        if(start!=-1){end=entry.getKey();break;} else start=entry.getKey();
        int[] res = new int[adjacentPairs.length + 1];
        res[0] = start;
        int cur = start, i=0, prev=-1;
        while(cur!=end)
        {
            for (int ch: H.get(cur)) if (ch==prev) continue;
            else {prev=cur; cur=ch; break;}
            res[++i] = cur;
        }
        return res;
    }
}