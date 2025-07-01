/*Complete the function below

struct Node {
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
  void inorder(Node *root,vector<int>&res)
  {
        if(!root) return;
        inorder(root->left,res);
        res.push_back(root->data);
        inorder(root->right,res);
  }
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here.
        vector<int>res;
        inorder(root,res);
        k--;
        return res.size()>k?res[k]:-1;
    }
};