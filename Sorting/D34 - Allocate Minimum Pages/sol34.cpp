//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int sum = 0, n = arr.size(),start=0;
        if(n<k)
        return - 1;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            start = max(start,arr[i]);
        }
        int end = sum,mid,ans=-1;
        while(start<=end){
            mid=start+(end-start)/2;
            int page = 0,count=1;
            for(int i=0; i<n;i++){
                page+=arr[i];
                if(page>mid){
                    count++;
                    page=arr[i];
                }
            }
            if(count<=k){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;

    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends