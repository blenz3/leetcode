class WordDictionary {
public:

    const std::string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    static const size_t MAX_CHARACTERS = 26;
    static const char WILD_CARD = '.';

    /** Initialize your data structure here. */
    WordDictionary() 
        : m_trie(new Node('\0'))
    {
    
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        insertWord(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if (word.empty()) 
            return false;

        return findWord(word, 0, m_trie);
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

    bool findWord(const std::string& s, size_t index, Node* prevNode) {
        if (s.empty() || index >= s.length() || prevNode == nullptr) {
            return false;
        } 

        std::string characters_to_try = (s[index] == WILD_CARD) ? ALPHABET : std::string(1, s[index]);
        for (auto c : characters_to_try) {
            Node* currentNode = prevNode->getNextNode(c);
            if (currentNode == nullptr) {
                continue;
            }

            if (s.length() - 1 == index && currentNode->end_of_word) {
                return true;
            }

            if (findWord(s, index + 1, currentNode)) {
                return true;
            }
        }

        return false;

    }
    
    Node* m_trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
