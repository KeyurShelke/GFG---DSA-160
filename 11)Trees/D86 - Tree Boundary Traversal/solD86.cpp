/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    private:
    bool isLeaf(Node* node){
        return (node->left == NULL && node->right == NULL);
    }
    
    void addLeftBoundary(Node* node, vector<int>& res){
        Node* cur = node->left;
        while(cur){
            if (!isLeaf(cur)) res.push_back(cur->data);
            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }
    
    void addLeaves(Node* node, vector<int>& res){
        if(!node) return;
        if(isLeaf(node)) {
            res.push_back(node->data);
            return;
        }
        addLeaves(node->left, res);
        addLeaves(node->right, res);
    }
    
    void addRightBoundary(Node* node, vector<int>& res){
        Node* cur = node->right;
        vector<int> tmp;
        while (cur) {
            if(!isLeaf(cur)) tmp.push_back(cur->data);
            if(cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }
        for (int i = tmp.size() - 1; i >= 0; --i)
            res.push_back(tmp[i]);
    }
        
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if (!root) return res;
        
        if(!isLeaf(root)) res.push_back(root->data);
        
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        
        return res;
    }
};

