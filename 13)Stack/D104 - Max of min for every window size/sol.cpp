
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int>left(n),right(n),res(n+1, INT_MIN);
        stack<int>s;
        
        for(int i = 0; i<n; i++){
            while(!s.empty() && arr[s.top()]>=arr[i])
            s.pop();
            left[i]=s.empty()? - 1: s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()]>=arr[i])
            s.pop();
            right[i]=s.empty() ? n: s.top();
            s.push(i);
        }
        for(int i=0 ; i<n;i++){
            int len=right[i]-left[i]-1;
            res[len]=max(res[len],arr[i]);
        }
        for(int i=n-1; i>=1; i--){
            res[i]=max(res[i],res[i+1]);
        }
        vector<int>ans(res.begin()+1,res.end());
        return ans;
        }
};