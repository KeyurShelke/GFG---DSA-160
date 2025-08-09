class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<vector<int>> arr;
        for(int i=0; i<start.size(); i++){
            arr.push_back({start[i],finish[i]});
        }
        
        sort(arr.begin(),arr.end(),
        [](const vector<int> & a, const vector<int>& b){
            return a[1]<b[1];
        });
        
        int count = 1;
        int j=0;
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i][0]>arr[j][1]){
                count++;
                j=i;
            }
        }
        return count;
    }
};