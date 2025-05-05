from typing import List


class Solution:
    def maximumProfit(self, prices) -> int:
        # code here
        res = 0
        
    # keep on adding the difference
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                res += prices[i] - prices[i -1]
                
        return res        
            


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        solution = Solution()
        res = solution.maximumProfit(arr)
        print(res)
        print("~")

# } Driver Code Ends