class Solution {
    public String predictPartyVictory(String senate) 
    {
        int n = senate.length();
        Queue<Integer> DQ = new LinkedList<Integer>();
        Queue<Integer> RQ = new LinkedList<Integer>();
        for (int i=0; i<n; i++)
        {
            if (senate.charAt(i)=='D') DQ.add(i);
            else RQ.add(i);
        }
        while (!DQ.isEmpty() && !RQ.isEmpty())
        {
            int d = DQ.poll(), r=RQ.poll();
            if (d<r) DQ.add(d+n);
            else RQ.add(r+n);
        }
        return (DQ.isEmpty())?"Radiant":"Dire";
    }
}