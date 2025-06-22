/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    int diameter(Node* root) {
        // Your code here
        int dia = 0;
        height(root,dia);
        return dia;
    }
    
    int height (Node* node, int & dia){
        if(!node) return 0;
        int lh = height(node->left, dia);
        int rh = height(node->right,dia);
        dia = max(dia, lh+rh);
        return 1 + max(lh,rh);
    }
};