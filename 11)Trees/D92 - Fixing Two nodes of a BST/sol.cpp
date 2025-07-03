/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  void inorder(Node *root,vector<Node*>&nodes)
  {
      if(!root) return;
      inorder(root->left,nodes);
      nodes.push_back(root);
      inorder(root->right,nodes);
  }
    void correctBST(Node* root) {
        // add code here.
        vector<Node*>nodes;
        inorder(root,nodes);
        
        Node *f=nullptr,*s=nullptr;
        for(int i=0;i<nodes.size()-1;i++)
        {
            if(nodes[i]->data>nodes[i+1]->data)
            {
                if(!f) f=nodes[i];
                s=nodes[i+1];
            }
        }
        swap(f->data,s->data);
    }
};