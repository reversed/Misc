public class Solution
{
    public String longestCommonPrefix(String q, String[] strs)
    {
        if (strs == null || strs.length == 0)
        {
            return "";
        }
                                
        if (strs.length == 1)
        {
            return strs[0];
        }
        
        Trie trie = new Trie();
        for (int i = 1; i < strs.length; ++i)
        {
            trie.insert(strs[i]);
        }
        return trie.searchLongestPrefix(q);
    }
}

class TrieNode {
    // R links to node children
    private TrieNode[] links;
    
    private final int R = 26;
    
    private boolean isEnd;
    
    // number of children non null links
    private int size;
    public void put(char ch, TrieNode node)
    {
        links[ch - 'a'] = node;
        size++;
    }
    
    public int getlinks()
    {
        return size;
    }
}

class Trie
{
    private TrieNode root;
    
    public Trie()
    {
        root = new TrieNode();
    }
    
    private String searchLongestPrefix(String word)
    {
        TrieNode node = root;
        StringBuilder prefix = new StringBuilder();
        for (int i = 0; i < word.length(); ++i)
        {
            char curLetter = word.charAt(i);
            if (node.containsKey(curLetter) && (node.getLinks() == 1) && (!node.isEnd()))
            {
                prefix.append(curLetter);
                node = node.get(curLetter);
            }
            else
            {
                return prefix.toString();
            }
        }
        return prefix.toString();
    }
}








