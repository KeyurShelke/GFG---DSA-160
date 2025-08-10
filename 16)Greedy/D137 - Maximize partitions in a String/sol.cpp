class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        vector<int>first(26,-1),last(26, -1);
        for(int i=0;i<s.size();i++){
            if(first[s[i]-'a']==-1)
            first[s[i]-'a']=i;
            last[s[i]-'a']=i;
        }
        int count=0;
        int end=0;
        for(int i=0;i<s.size();i++){
            end=max(end,last[s[i]-'a']);
            if(i==end)
            count++;
        }
        return count;
    }
};