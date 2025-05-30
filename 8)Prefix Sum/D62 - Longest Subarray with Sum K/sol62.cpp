class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map <int,int> mpp;
        
        int res = 0;
        int prefSum = 0;
        
        for(int i = 0; i < arr.size() ; i++){
            prefSum+=arr[i];
            
            if(prefSum == k){
                res = i+1;
            }
            
            else if(mpp.find(prefSum-k) != mpp.end()){
                res= max(res, i-mpp[prefSum-k]);
            }
            
            if(mpp.find(prefSum) == mpp.end()){
                mpp[prefSum] = i;
            }
        }
        return res;
        
    }
};