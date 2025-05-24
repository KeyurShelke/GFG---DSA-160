class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int i=0, j=0;
        int n=arr.size();
        int currSum=0;
        while(j<n){
            currSum+=arr[j];
            while(currSum>target && i<=j){
                currSum-=arr[i];
                i++;
            }
            if(currSum==target){
                return {i+1,j+1};
            }
            j++;
        }
        return {-1};
    }
};