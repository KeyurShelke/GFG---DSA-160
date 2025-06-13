class Solution {
  public:
  void solve(string &s, set<string> &ans, int idx){
      if(idx >= s.size()){
          ans.insert(s);
          return;
      }
      
      for(int i=idx; i<s.size(); i++){
          swap(s[idx], s[i]);
          solve(s, ans, idx+1);
          swap(s[idx], s[i]);
      }
  }
    vector<string> findPermutation(string &s) {
        set<string> ans;
        solve(s, ans, 0);
        return vector<string>(ans.begin(), ans.end());
    }
};
