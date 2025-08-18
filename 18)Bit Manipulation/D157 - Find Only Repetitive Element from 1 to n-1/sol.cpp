// User function Template for C++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int Xor=arr[0];
        for(int i=1;i<arr.size();i++){
            Xor^=arr[i];
            Xor^=i;
        }
        return Xor;
    }
};