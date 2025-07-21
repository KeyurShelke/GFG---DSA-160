class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int i = 0, j=0, n=arr.size(), maxLen=0, start=0;
        multiset<int>window;
        while(j<n){
            window.insert(arr[j]);
            while(*window.rbegin()-*window.begin()>x){
                window.erase(window.find(arr[i]));
                i++;
            }
            if(j-i+1>maxLen){
                maxLen = j-i+1;
                start = i;
            }
            j++;
        }
        return vector<int>(arr.begin() + start, arr.begin()+start+maxLen);
        }
    };