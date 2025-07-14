class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n = arr.size();
        vector<int>span(n);
        stack<int> s;
        
        for(int i=0; i<n; i++){
            int curr = arr[i];
            while(!s.empty() && arr[s.top()] <=curr){
                s.pop();
            }
            if(s.empty()){
                span[i] = i+1;
            }
            else{
                span[i] = i-s.top();
            }
            s.push(i);
        }
        return span;
    }
};