class Solution {
    public String destCity(List<List<String>> paths) 
    {
        HashMap<String,String> G = new HashMap();
        for(List<String> path: paths) G.put(path.get(0), path.get(1));
        String cur = paths.get(0).get(0);
        while(G.containsKey(cur)) cur = G.get(cur);
        return cur;
    }
}