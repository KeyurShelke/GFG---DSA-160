class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        stack<int> st;
        int res=0;
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                int pop_height = arr[st.top()];
                st.pop();
                if(st.empty())break;
                int d = i-st.top()-1;
                int water = min(arr[st.top()],arr[i])-pop_height;
                res+=d*water;
            }
            st.push(i);
        }
        return res;
        
    }
};