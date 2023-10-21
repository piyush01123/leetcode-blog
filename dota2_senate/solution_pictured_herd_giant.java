class Solution {
    public String predictPartyVictory(String senate) 
    {
        Queue<Character> Q = new LinkedList<Character>();
        int ctrD=0, ctrR=0;
        for (int i=0; i<senate.length(); i++)
        {
            char ch = senate.charAt(i);
            if (ch=='D') ctrD++;
            else if (ch=='R') ctrR++;
            Q.add(ch);
        }
        int ptsD=0, ptsR=0;
        while (Q.size()>1)
        {
            char ch = Q.poll();
            if (ch=='D') if (ptsR>0) {ptsR--; ctrD--;} else {Q.add(ch); ptsD++;}
            if (ch=='R') if (ptsD>0) {ptsD--; ctrR--;} else {Q.add(ch); ptsR++;}
            if (ctrD==0 || ctrR==0) break;
        }
        return ((Q.poll()=='R')?"Radiant":"Dire");
    }
}