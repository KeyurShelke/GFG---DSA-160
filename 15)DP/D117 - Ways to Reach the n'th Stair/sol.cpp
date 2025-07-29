class Solution {
  public:
    int countWays(int n) {
        // your code here
        int prev0 = 1, prev1=1;
        
        for(int i=1; i<n; i++){
            int temp = prev1+prev0;
            prev0=prev1;
            prev1=temp;
        }
        
        return prev1;
    }
};
