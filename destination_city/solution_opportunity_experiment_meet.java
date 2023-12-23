class Solution {
    public String destCity(List<List<String>> paths) 
    {
        Set<String> nodes = new HashSet();
        for(List<String> path: paths) nodes.add(path.get(0));
        for(List<String> path: paths) if(!nodes.contains(path.get(1))) return path.get(1);
        return "";         
    }
}