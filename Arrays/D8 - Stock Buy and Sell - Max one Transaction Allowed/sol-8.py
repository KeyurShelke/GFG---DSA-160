class Solution:
    def maximumProfit(self, prices):
        # code here
        minSoFar = prices[0]
        res = 0
        
        # Update the minimum value seen so far
        # if we see smaller
        for i in range(1, len(prices)):
            minSoFar = min(minSoFar, prices[i])
            
            # Update result if we get more profit
            res = max(res, prices[i] - minSoFar)
            
        return res    


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())  # Read number of test cases
    for _ in range(t):
        # Read input and split it into a list of integers
        prices = list(map(int, input().split()))
        # Create a Solution object and calculate the result
        obj = Solution()
        result = obj.maximumProfit(prices)
        # Print the result
        print(result)

# } Driver Code Ends