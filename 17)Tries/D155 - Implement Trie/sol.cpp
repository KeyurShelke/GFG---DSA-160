// User function template for C++
class Trie {
    struct Node {
        Node* links[26];
        bool isEnd;
        Node() {
            for (int i = 0; i < 26; i++) links[i] = nullptr;
            isEnd = false;
        }
    };
    Node* root;
    
  public:

    Trie() {
        // implement Trie
        root = new Node();
    }

    void insert(string &word) {
        // insert word into Trie
        Node* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->links[idx]) {
                node->links[idx] = new Node();
            }
            node = node->links[idx];
        }
        node->isEnd = true;
    }

    bool search(string &word) {
        // search word in the Trie
        Node* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->links[idx]) return false;
            node = node->links[idx];
        }
        return node->isEnd;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->links[idx]) return false;
            node = node->links[idx];
        }
        return true;
    }
};
