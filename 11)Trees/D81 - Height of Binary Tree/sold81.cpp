/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int result(Node* root) {
        if(!(root)) return 0;
        else return 1+max(result(root->left),result(root->right));
    }
    int height(Node* node) {
        return result(node)-1;
    }
};