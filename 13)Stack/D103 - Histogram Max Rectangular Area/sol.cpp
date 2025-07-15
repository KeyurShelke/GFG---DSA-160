class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        stack<int> s;
        vector<int> left(n), right(n);
        
        for (int i = 0; i<n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        while (!s.empty()) s.pop();
        
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, arr[i] * width);
        }
        
        return maxArea;
    }
};
