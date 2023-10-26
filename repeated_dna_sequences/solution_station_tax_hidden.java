class Solution {
    public List<String> findRepeatedDnaSequences(String s) 
    {
        if (s.length()<11) return new ArrayList();
        Map<String,Integer> H = new HashMap();
        for (int i=0; i<=s.length()-10; i++)
        {
            String sub = s.substring(i, i+10);
            H.put(sub, H.getOrDefault(sub,0)+1);
        }
        List<String> res = new ArrayList();
        for (Map.Entry<String,Integer> entry: H.entrySet())
            if (entry.getValue()>1) res.add(entry.getKey());
        return res;
    }
}