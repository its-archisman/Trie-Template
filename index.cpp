struct *Node
{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL)
    }
    void put(char ch, Node *node)
    {
        links[ch-'a']=node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    bool setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
}
class Trie
{
    Trie()
    {
        root=new Node();
    }
    void insert(string word)
    {
        Node *node=root;
        for(int i=0; i<word.length(); i++)
        {
            if(!node->containsKey(word[i]))
                node->put(word[i], new Node());
        
            // Moves to the reference trie
            node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word)
    {
        Node *node=root;
        for(int i=0; i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
                return false;
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    bool startsWith(string word)
    {
        Node *node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node.containsKey(word[i]))
                return false;
            node=node->get(word[i]);
        }
        return true;
    }    
}
