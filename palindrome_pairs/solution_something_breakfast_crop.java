public class Trie {
    List<Trie> children;
    List<Integer> palIndices;
    int sIndex;
    Trie() {
        children = new ArrayList();
        for (int i = 0; i < 26; i++) children.add(null);
        palIndices = new ArrayList();
        sIndex = -1;
    }
}


class Solution {
    public boolean isPalindrome(String word, int i, int j) 
    {
        while (i < j) if (word.charAt(i++) != word.charAt(j--)) return false;
        return true;
    }

    public void addWord(Trie root, String word, int wi) 
    {
        for (int i = word.length() - 1; i >= 0; i--) 
        {
            if (isPalindrome(word, 0, i)) root.palIndices.add(wi);
            int pos = word.charAt(i) - 'a';
            if (root.children.get(pos) == null) root.children.set(pos, new Trie());
            root = root.children.get(pos);
        }
        root.sIndex = wi;
        root.palIndices.add(wi);
    }

    public void search(Trie root, String word, int wi, List<List<Integer>> res) 
    {
        for (int i = 0; i < word.length(); i++) 
        {
            if (root.sIndex != -1 && root.sIndex != wi && isPalindrome(word, i, word.length() - 1))
                res.add(List.of(wi, root.sIndex));
            int pos = word.charAt(i) - 'a';
            if (root.children.get(pos) == null) return;
            root = root.children.get(pos);
        }
        for (int wj : root.palIndices)  if (wj != wi) res.add(List.of(wi, wj));
    }

    public List<List<Integer>> palindromePairs(String[] words) 
    {
        Trie root = new Trie();
        for (int i = 0; i < words.length; i++) addWord(root, words[i], i);
        List<List<Integer>> res = new ArrayList();
        for (int i = 0; i < words.length; i++) search(root, words[i], i, res);
        return res;        
    }
}