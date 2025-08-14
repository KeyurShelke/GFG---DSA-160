// User function Template for C++

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
  public:
  unordered_map<Node*, Node*> mp;
    Node* dfs(Node* node) {
        if (!node) return NULL;
        
        if (mp.find(node) !=mp.end())
        return mp[node];
        
        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode;
        
        for (auto neigh : node->neighbors) {
            cloneNode->neighbors.push_back(dfs(neigh));
        }
        
        return cloneNode;
    }
    
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
