/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;
            
            for (int i = 0; i < levelSize; ++i) {
                Node* current = q.front();
                q.pop();
                level.push_back(current ->data);
                
                if (current ->left) q.push(current->left);
                if (current ->right) q.push(current->right);
            }
            result.push_back(level);
        }
        return result;
    }
};