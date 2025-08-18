class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        unordered_set<char> allChars;
        
        for (auto &w : words) {
            for (char c : w) {
                allChars.insert(c);
                if (!adj.count(c)) adj[c] = {};
                if (!indegree.count(c)) indegree[c] = 0;
            }
        }
        
        for (int i =0; i < (int)words.size() - 1; i++) {
            string &w1 = words[i];
            string &w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());
            bool foundDiff = false;
            
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    foundDiff = true;
                    break;
                }
            }
            if (!foundDiff && w1.size() > w2.size()) {
                return "";
            }
        }
        queue<char> q;
        for (auto &p : indegree) {
            if (p.second == 0) q.push(p.first);
        }
        
        string order;
        while (!q.empty()) {
            char curr = q.front(); q.pop();
            order.push_back(curr);
            
            for (char neigh : adj[curr]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        
        if ((int)order.size() != (int)allChars.size()) {
            return "";
        }
        return order;
    }
};
