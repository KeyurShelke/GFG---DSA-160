class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        vector<int> dp(sum+1,0);
        dp[0]=1;
        
        for(int coin : coins){
            for(int s = coin ; s<=sum;s++){
                dp[s] += dp[s-coin];
            }
        }
        return dp[sum];
    }
};