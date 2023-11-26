class Solution {
    public List<String> buildArray(int[] target, int n) 
    {
        List<String> res = new ArrayList();
        int index=0;
        for (int cur=1; cur<=n; cur++)
        {
            res.add("Push");
            if (target[index]==cur) index++;
            else res.add("Pop");
            if (index==target.length) return res;
        }
        return new ArrayList(); //wont come here
    }
}