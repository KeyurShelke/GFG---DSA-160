// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        
        sort(arr.begin(),arr.end());
        vector<int> ans;
        int left = 0;
        int right = arr.size()-1;
        int diff = INT_MAX;
        
        while(left<right){
            int sum = arr[left] + arr[right];
            
            if(abs(sum-target) < diff){
                diff = abs(sum - target);
                ans = {arr[left],arr[right]};
            }
            
            if(sum < target){
                left++;
            }else if (sum>target){
                right--;
            }else{
                return ans;
            }    
            
        }
        return ans;
    }
};