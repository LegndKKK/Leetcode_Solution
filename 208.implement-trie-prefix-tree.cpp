class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *cur = root;
        for (char c : word)
        {
            if (cur->p[c - 'a'] == NULL)
                cur->p[c - 'a'] = new TrieNode;
            cur = cur->p[c - 'a'];
        }
        cur->flag = 1;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *cur = root;
        for (char c : word)
        {
            if (cur->p[c - 'a'] == NULL)
                return false;
            cur = cur->p[c - 'a'];
        }
        if (cur->flag)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *cur = root;
        for (char c : prefix)
        {
            if (cur->p[c - 'a'] == NULL)
                return false;
            cur = cur->p[c - 'a'];
        }
        if (cur->flag)
            return true;
        for (int i = 0; i < 26; i++)
            if (cur->p[i])
                return true;
        return false;
    }

private:
    struct TrieNode
    {
        TrieNode()
        {
            p.resize(26, 0);
            flag = 0;
            for (int i = 0; i < 26; i++)
                p[i] = NULL;
        }
        int flag;
        vector<TrieNode *> p;
    };
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */