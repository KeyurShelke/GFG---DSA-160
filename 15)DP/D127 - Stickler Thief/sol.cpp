class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return arr[0];
        }
        
        int secondLast = 0, last = arr[0];
        
        int res;
        for(int i = 1; i < n; i++){
            res = max(arr[i] + secondLast,last);
            secondLast = last;
            last = res;
        }
        return res;
    }
};