#include <iostream>
#include <string>
#include <vector>

class Trie {
private:
    struct TrieNode {
        bool is_end_of_word;
        std::vector<TrieNode*> children;

        TrieNode(int alphabet_size) 
            : is_end_of_word(false), children(alphabet_size, nullptr) {}

        ~TrieNode() {
            // Recursive clean-up of child nodes
            for (TrieNode* child : children) {
                delete child;
            }
        }
    };

    TrieNode* root;
    int alphabet_size;
    char base_char;

    // Private helper: Traverses the trie and returns the node where prefix ends.
    // Reused by search(), starts_with(), and delete_word()!
    TrieNode* find_node(const std::string& key) const {
        TrieNode* current = root;
        for (char c : key) {
            int index = c - base_char;
            if (index < 0 || index >= alphabet_size || !current->children[index]) {
                return nullptr;
            }
            current = current->children[index];
        }
        return current;
    }

    void print_helper(TrieNode* node, std::string current_prefix) const {
        if (!node) return;

        if (node->is_end_of_word) {
            std::cout << current_prefix << "\n";
        }

        for (int i = 0; i < alphabet_size; ++i) {
            if (node->children[i]) {
                print_helper(node->children[i], current_prefix + static_cast<char>(base_char + i));
            }
        }
    }

public:
    // Reusable constructor: Defaults to lowercase 'a'-'z', 
    // but can be initialized for digits ('0', 10), uppercase ('A', 26), etc.
    Trie(int alphabet_size = 26, char base_char = 'a')
        : alphabet_size(alphabet_size), base_char(base_char) {
        root = new TrieNode(alphabet_size);
    }

    ~Trie() {
        delete root; // Automatically triggers recursive ~TrieNode()
    }

    // Insert a word
    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - base_char;
            if (index < 0 || index >= alphabet_size) return; // Guard clause

            if (!current->children[index]) {
                current->children[index] = new TrieNode(alphabet_size);
            }
            current = current->children[index];
        }
        current->is_end_of_word = true;
    }

    // Search for a full word (Reuses find_node)
    bool search(const std::string& word) const {
        TrieNode* node = find_node(word);
        return node != nullptr && node->is_end_of_word;
    }

    // Check if prefix exists (Reuses find_node)
    bool starts_with(const std::string& prefix) const {
        return find_node(prefix) != nullptr;
    }

    // Unmark a word without breaking other branches
    void delete_word(const std::string& word) {
        TrieNode* node = find_node(word);
        if (node) {
            node->is_end_of_word = false;
        }
    }

    // Print all words
    void print() const {
        print_helper(root, "");
    }
};

int main() {
    // 1. Standard Lowercase Trie
    Trie trie;
    trie.insert("geek");
    trie.insert("geeks");
    trie.insert("code");
    trie.insert("coder");

    std::cout << "--- Standard Trie ---" << std::endl;
    std::cout << "search('code'): " << trie.search("code") << std::endl;      // 1 (true)
    std::cout << "starts_with('ge'): " << trie.starts_with("ge") << std::endl; // 1 (true)

    trie.delete_word("code");
    std::cout << "search('code') after delete: " << trie.search("code") << std::endl; // 0 (false)
    std::cout << "starts_with('cod') after delete: " << trie.starts_with("cod") << std::endl; // 1 (true, 'coder' exists)

    // 2. Reused for Digits/Phone Numbers! ('0' to '9')
    Trie phone_trie(10, '0');
    phone_trie.insert("911");
    phone_trie.insert("18005550199");

    std::cout << "\n--- Reused for Digits ---" << std::endl;
    std::cout << "starts_with('1800'): " << phone_trie.starts_with("1800") << std::endl; // 1 (true)

    return 0;
}
