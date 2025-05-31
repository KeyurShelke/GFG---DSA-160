class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        map<int,int>mp;
        int presum = 0,res=0;
        for(int i=0; i<arr.size(); i++)
        {
            presum += (arr[i]==0)?-1:1;
            if(presum==0)res=i+1;
            if(mp.find(presum) !=mp.end())
            res=max(res,i-mp[presum]);
            else mp[presum] = i;
        }
        return res;
    }
};