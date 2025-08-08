class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n = arr.size();
        int res=0;
        int maxdep=dep[0];
        for(int i=1;i<n;i++){
            maxdep=max(maxdep,dep[i]);
        }
        vector<int>v(maxdep+2,0);
        for(int i=0;i<n;i++){
            v[arr[i]]++;
            v[dep[i]+1]--;
        }
        int count=0;
        for(int i=0;i<=maxdep+1;i++){
            count+=v[i];
            res=max(res,count);
        }
        return res;
    }
};
