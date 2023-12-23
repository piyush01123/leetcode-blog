class Solution {
    public boolean isPathCrossing(String path) 
    {
        int n=path.length(), x=0, y=0;
        HashSet<String> points = new HashSet();
        points.add("0,0");
        for(int i=0; i<n; i++)
        {
            char ch = path.charAt(i);
            if(ch=='N') y++;
            if(ch=='S') y--;
            if(ch=='E') x++;
            if(ch=='W') x--;
            String xy = Integer.toString(x)+","+Integer.toString(y);
            if (points.contains(xy)) return true;
            points.add(xy);
        }
        return false;
    }
}