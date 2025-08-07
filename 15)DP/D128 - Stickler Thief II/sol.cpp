class Solution {
  public:
        int solve(vector<int> & arr, int i, int n) {
            int p = 0, e = 0;
            for(int j = i; j <= n; j++) {
                int temp = max(p, e+arr[j]);
                e = p;
                p = temp;
            }
            return p;
        }
        int maxValue(vector<int>& arr){
            int n = arr.size();
            if(n==0) return 0;
            if(n==1) return arr[0];
            int case1 = solve(arr,0,n-2);
            int case2 = solve(arr,1,n-1);
            return max(case1, case2);
    }
};
