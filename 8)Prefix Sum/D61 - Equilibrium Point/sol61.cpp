class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        int totalsum = 0;
        for(int i:arr){
            totalsum+=i;
        }
        int leftsum = 0;
        for(int i = 0 ; i<n ; i++){
            totalsum -= arr[i];
        if(leftsum == totalsum){
            return i;
        }   
        leftsum += arr[i];
        }
        return -1;
    }
};