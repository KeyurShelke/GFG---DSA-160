class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), compareByLength);
        
        unordered_map<string, int> dp;
        int maxChain = 1;
        
        for(int i = 0; i<words.size(); i++){
            string word = words[i];
            int best = 0;
            
            for(int j=0; j<word.length(); j++){
                string prev = word.substr(0,j) + word.substr(j+1);
                if(dp.find(prev) != dp.end()){
                    if(dp[prev] > best) {
                        best = dp[prev];
                    }
                }
            }
            dp[word] = best +1;
    
            if(dp[word] > maxChain){
                maxChain = dp[word];
            }
        }
        return maxChain;
    }
    static bool compareByLength(const string& a, const string& b){
        return a.length() < b.length();
    }
};