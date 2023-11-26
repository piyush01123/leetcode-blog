class Solution {
    void dfs(Map<Integer, List<Integer>> H, int[]res, int cur, int index, int par)
    {
        res[index] = cur;
        for (int ch: H.get(cur)) if (ch==par) continue; else dfs(H,res,ch,index+1,cur);
    }
    public int[] restoreArray(int[][] adjacentPairs) 
    {
        Map<Integer, List<Integer>> H = new HashMap();
        for (int[] pair: adjacentPairs)
        {
            H.computeIfAbsent(pair[0], k->new ArrayList()).add(pair[1]);
            H.computeIfAbsent(pair[1], k->new ArrayList()).add(pair[0]);
        }
        int cur=-1;
        for(var entry: H.entrySet())if(entry.getValue().size()==1)
                                    {cur=entry.getKey();break;}
        int[] res = new int[adjacentPairs.length + 1];
        dfs(H,res,cur,0,-1);
        return res;
    }
}