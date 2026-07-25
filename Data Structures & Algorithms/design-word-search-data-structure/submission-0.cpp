class WordDictionary {
private:
    struct TrieNode {
        bool is_end_of_word = false;
        vector<TrieNode*> children;

        TrieNode() : children(26, nullptr) {}

        ~TrieNode() {
            for(TrieNode* child : children) {
                delete child;
            }
        }
    };

    TrieNode* root;

    bool search_helper(const string& word, int index, TrieNode* node) {
        if(!node) return false;
        if(index == word.size()) return node->is_end_of_word;

        char c = word[index];

        if(c == '.') { // wildcard: try every possible branch at this level
            for(TrieNode* child : node->children) {
                if(child && search_helper(word, index + 1, child)) {
                    return true;
                }
            }
            return false;
        } else {
            int char_idx = c - 'a';
            return search_helper(word, index + 1, node->children[char_idx]);
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }

    ~WordDictionary() {
        delete root;
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        for(char c : word) {
            int index = c - 'a';
            if(!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->is_end_of_word = true;
    }
    
    bool search(string word) {
        return search_helper(word, 0, root);
    }
};
