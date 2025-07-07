class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        sort(arr.begin(), arr.end());
        
        vector<int> ans;
        int j = arr.size() - 1;
        
        while(k--){
            ans.push_back(arr[j--]);
        }
        
        return ans;
    }
};