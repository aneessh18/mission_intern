class TrieNode
{
    TrieNode [] ptrs;
    boolean isend;
    public TrieNode()
    {
        this.ptrs = new TrieNode[26];
    }
}
class Trie {

    private TrieNode root;
    public Trie() {
        root = new  TrieNode();
    }
    public void insert(String word) {
        TrieNode temp=root;
        for(int i=0;i<word.length();i++)
        {
            int x=word.charAt(i)-'a';
            if(temp.ptrs[x]==null)
            {
                temp.ptrs[x]= new TrieNode();
                temp=temp.ptrs[x];
            }
            else
            {
                temp=temp.ptrs[x];
            }
        }
        temp.isend=true;
    }
    
    public boolean search(String word) 
    {
        TrieNode temp=root;
        for(int i=0;i<word.length();i++)
        {
            int x=word.charAt(i)-'a';
            if(temp.ptrs[x]==null)
                return false;
            else
            {
                temp=temp.ptrs[x];
            }
        }
        if(temp.isend==true)
        return true;
        else
            return false;
    }
    public boolean startsWith(String prefix)
    {
        TrieNode temp=root;
        for(int i=0;i<prefix.length();i++)
        {
            int x=prefix.charAt(i)-'a';
            if(temp.ptrs[x]==null)
                return false;
            else
                temp=temp.ptrs[x];
        }
        return true;
    }
}
