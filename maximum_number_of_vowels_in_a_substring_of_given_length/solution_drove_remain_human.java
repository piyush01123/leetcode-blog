class Solution {
    public int maxVowels(String s, int k) 
    {
       HashSet<Character> vowels = new HashSet<Character>(Arrays.asList('a','e','i','o','u'));
       int ctr=0;
       for (int i=0; i<k; i++) if(vowels.contains(s.charAt(i))) ctr++;
       int res=ctr;
       for (int i=k; i<s.length(); i++)
       {
           char inc=s.charAt(i), out=s.charAt(i-k);
           if (vowels.contains(inc)) ctr++;
           if (vowels.contains(out)) ctr--;
           res = Math.max(res, ctr);
       }
       return res;
    }
}