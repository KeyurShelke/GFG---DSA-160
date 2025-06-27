// User Fuction template for C++
/*
// Tree Node
class Node {
public:
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
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
    int dfs(Node* node, int& maxSum){
        if(!node) return 0;
        
        int left = max(0, dfs(node->left,maxSum));
        int right = max(0,dfs(node->right,maxSum));
        
        maxSum = max(maxSum, node->data+left+right);
        return node -> data + max(left,right);
    }
};