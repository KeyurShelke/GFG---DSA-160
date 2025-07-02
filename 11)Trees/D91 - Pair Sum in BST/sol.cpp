/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    bool preorder(Node *root, int target, unordered_map<int, int>& map) {
        // your code here.
        if(!root) return false;
        
        int val = target - root->data;
        
        if(map.find(val) != map.end()) return true;
        map[root->data]++;
        
        return preorder(root->left, target, map) || preorder(root->right, target, map);
        
    }
    
    bool findTarget(Node *root, int target) {
        unordered_map<int, int> map;
        
        return preorder(root, target, map);
    }
};