class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int n = arr.size();
        int ans = arr[0];
        for(int i=1; i<n; ++i) ans ^= arr[i];
        return ans;
    }
};