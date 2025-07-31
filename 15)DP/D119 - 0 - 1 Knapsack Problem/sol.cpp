class Solution {
  
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<int> prev(W+1,0), cur(W+1,0);
        for(int w=wt[0];w<=W;w++){
            prev[w]=val[0];
        }
        for(int ind=1; ind<n; ind++){
            for(int w=0; w<=W; w++){
                int notTake=0+prev[w];
                int Take=INT_MIN;
                if(wt[ind]<=w){
                    Take=val[ind]+prev[w-wt[ind]];
                }
                cur[w]=max(Take,notTake);
            }
            prev=cur;
        }
        return prev[W];
    }
};