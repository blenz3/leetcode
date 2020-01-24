class Trie {
public:
    static const size_t MAX_CHARACTERS = 26;
    
    /** Initialize your data structure here. */
    Trie() 
        : m_trie(new Node('\0')) 
    {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertWord(word);   
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return findWord(word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWithWord(prefix);
    }
    
private:

    struct Node {
        char val;
        bool end_of_word;
        std::array<Node*, MAX_CHARACTERS> children;
        
        Node() 
            : val('\0')
            , end_of_word(false)
        {

        }
        Node(char c) 
            : val(c) 
            , end_of_word(false)
        {
            children.fill(nullptr);
        }
        
        Node* createNextNode(char c) {
            Node* node = getNextNode(c);
            if (node == nullptr) {
                node = addNextNode(c);
            }

            return node;
        }

        Node* getNextNode(char c) {
            return children[getIndex(c)];
        }
        
        Node* addNextNode(char c) {
            Node* child = new Node(c);
            children[getIndex(c)] = child;
            return child;
        }
        
        size_t getIndex(char c) {
            return static_cast<size_t>(::tolower(c) - 'a');
        }

        bool containsCharacter(char c) {
            return (getNextNode(c) != nullptr);
        }
        
    };
    
    void insertWord(const std::string& s) {
        if (s.empty()) {
            return;
        }

        Node* currentNode = m_trie;
        for (int i = 0; i < s.length(); ++i) {
            currentNode = currentNode->createNextNode(s[i]);
        }

        currentNode->end_of_word = true;
    }

    bool findWord(const std::string& s) {
        Node* lastCharacter = seekToEnd(s);
        return (lastCharacter == nullptr) ? false : lastCharacter->end_of_word;
    }

    bool startsWithWord(const std::string& s) {
        return (seekToEnd(s) != nullptr);
    }

    Node* seekToEnd(const std::string& s) {
        if (s.empty()) {
            return nullptr;
        } else if (m_trie == nullptr) {
            return nullptr;
        }

        Node* currentNode = m_trie;
        for (auto c : s) {
            currentNode = currentNode->getNextNode(c);
            if (currentNode == nullptr) {
                return nullptr;
            }
        }

        return currentNode;
    }
    
    Node* m_trie;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
