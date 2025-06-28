/*
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
    int sumK(Node *root, int k) {
        // code here
        unordered_map<long long, int> prefix;
        prefix[0] = 1;
        return dfs(root, 0, k, prefix);
        }
        int dfs(Node* node, long long curr, int k, unordered_map<long long, int>& prefix){
            if(!node) return 0;
            
            curr += node->data;
            int count = prefix[curr-k];
            
            prefix[curr]++;
            count += dfs(node->left, curr, k, prefix);
            count += dfs(node->right, curr, k, prefix);
            prefix[curr]--;
            
            return count;
        }
};