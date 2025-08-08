// User function Template for C++
class Solution {
    unordered_map<string, int> memo;
    
    int solve(string &s, int i, int j, bool isTrue){
        if ( i > j) return 0;
        
        if ( i == j){
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
        if (memo.count(key)) return memo[key];
        
        int ways = 0;
        
        for (int k = i + 1; k < j; k += 2) {
            char op = s[k];
            
            int lt = solve(s,i,k-1, true);
            int lf = solve(s,i,k-1, false);
            int rt = solve(s,k+1,j, true);
            int rf = solve(s,k+1,j, false);
            
            if (op == '&') {
                if (isTrue) ways += lt * rt;
                else ways += lt * rf + lf * rt + lf * rf; 
            }
            else if (op == '|'){
                if (isTrue) ways += lt * rt + lt * rf + lf * rt;
                else ways += lf * rf;
            }
            else if (op == '^'){
                if (isTrue) ways += lt * rf + lf * rt;
                else ways += lt * rt + lf * rf;
            }
        }
        return memo[key] = ways;
    }
  public:
    int countWays(string &s) {
        // code here
        memo.clear();
        return solve(s, 0, s.size() - 1, true);
        
    }
};