class PrefixTree {
private:
    struct PrefixTreeNode {
        bool is_end_of_word;
        vector<PrefixTreeNode*> children;

        PrefixTreeNode(int alphabet_size) : is_end_of_word(false), children(alphabet_size, nullptr) {}
    };

    PrefixTreeNode* root;
    int alphabet_size;
    char base_char;

    PrefixTreeNode* find_node(const string& key) const {
        PrefixTreeNode* current = root;

        for(char c : key) {
            int index = c - base_char;
            if(index < 0 || index >= alphabet_size || !current->children[index]) {
                return nullptr;
            }
            current = current->children[index];
        }
        return current;
    }

public:
    PrefixTree(int alphabet_size = 26, char base_char = 'a') 
        : alphabet_size(alphabet_size), base_char(base_char) {

        root = new PrefixTreeNode(alphabet_size);
    }
    
    void insert(string word) {
        PrefixTreeNode* current = root;
        for(char c : word) {
            int index = c - base_char;
            if (index < 0 || index >= alphabet_size) return;

            if(!current->children[index]) {
                current->children[index] = new PrefixTreeNode(alphabet_size);
            }
            current = current->children[index];
        }
        current->is_end_of_word = true;
    }
    
    bool search(string word) {
        PrefixTreeNode* node = find_node(word);
        return node!=nullptr && node->is_end_of_word;
    }
    
    bool startsWith(string prefix) {
        return find_node(prefix) != nullptr;
    }
};
