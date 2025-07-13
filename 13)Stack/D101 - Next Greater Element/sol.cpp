class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& nums) {
        // code here
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--)
        {
            int idx = i % n;
            while (!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            
            if(!st.empty()){
                result[i] = st.top();
            }
            
            st.push(nums[i]);
        }
        return result;
    }
};