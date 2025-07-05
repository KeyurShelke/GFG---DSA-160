/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    void serializeHelper(Node* root, vector<int> &res) {
        if (root == nullptr){
            res.push_back(-1);
            return;
        }
        res.push_back(root->data);
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }
    
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> res;
        serializeHelper(root, res);
        return res;
    }
    
    Node* deSerializeHelper(vector<int> &arr, int &index){
        if (index >= arr.size() || arr[index] == -1){
            index++;
            return nullptr;
        }
        
        Node* root = new Node(arr[index++]);
        root->left = deSerializeHelper(arr, index);
        root->right = deSerializeHelper(arr, index);
        return root;
    }
    
    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        int index = 0;
        return deSerializeHelper(arr, index);
    }
};