class Solution {
  public:
  int t[1001][1001];
  
  int LCS(string &s1, string &s2, int n, int m){
      if (n==0 || m==0)
      return 0;
      
      if(t[n][m] != -1)
      return t[n][m];
      
      if (s1[n-1]==s2[m-1]) {
          return t[n][m] = 1 + LCS(s1, s2, n-1, m-1);
      }
      else {
          return t[n][m] = max(LCS(s1, s2, n,  m-1), LCS(s1, s2, n-1, m));
      }
  }
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.length();
        int m = s2.length();
        memset(t, -1, sizeof(t));
        return LCS(s1, s2, n, m);
    }
};
