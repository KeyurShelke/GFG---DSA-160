class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    void inorder(Node *root,vector<int>&inord)
    {
        if(!root) return;
        inorder(root->left,inord);
        inord.push_back(root->data);
        inorder(root->right,inord);
    }
    
    bool isBST(Node* root) {
        // Your code here
        vector<int>inord;
        inorder(root,inord);
        for(int i=1;i<inord.size();i++)
        {
            if(inord[i]<=inord[i-1] || inord[i] == inord[i-1])
            {
                return false;
            }
        }
        return true;
    }
};