
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n=arr.size();
        int left=0,right=n-1;
        
        int count=0;
        while(left<right){
            int sum=arr[left]+arr[right];
            if(sum>target)right--;
            else if(sum<target)left++;
            else{
                int ele1=arr[left],ele2=arr[right];
                int cnt1=0,cnt2=0;
                while(left <= right && arr[left] == ele1){
                    cnt1++;
                    left++;
                }
                while(left <= right && arr[right]==ele2){
                    cnt2++;
                    right--;
                }
                if(ele1==ele2) count+=cnt1*(cnt1-1)/2;
                else count+=cnt1*cnt2;
            
                
            }
        }
        return count;
    }    
};