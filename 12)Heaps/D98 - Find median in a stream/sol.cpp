class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<double> result;
        
        for (int num : arr){
            maxHeap.push(num);
            
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            if (maxHeap.size() == minHeap.size()) {
                result.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                result.push_back(maxHeap.top());
            }    
        }
        return result;
    }
};
