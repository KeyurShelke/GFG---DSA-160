// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
  int preIndex = 0;
  unordered_map<int, int> inMap;
  
  Node *build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd){
      if(inStart > inEnd) return NULL;
      
      int rootVal = preorder[preIndex++];
      Node* root = new Node(rootVal);
      
      int inIndex = inMap[rootVal];
      
      root->left = build(preorder, inorder, inStart, inIndex - 1);
      root->right = build(preorder, inorder, inIndex + 1, inEnd);
      
      return root;
  }
  
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        preIndex = 0;
        inMap.clear();
        for (int i = 0; i < inorder.size(); ++i)
            inMap[inorder[i]] = i;
            
        return build(preorder, inorder, 0, inorder.size() - 1);    
        
        
    }
};