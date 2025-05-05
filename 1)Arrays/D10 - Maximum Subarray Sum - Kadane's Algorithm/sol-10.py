class Solution:
    def maxSubArraySum(self, arr):
        # Your code here
        res = arr[0]
        maxEnding = arr[0]
        
        for i in range(1, len(arr)):
            
            #find the max sum ending at index i by either extending
            #the max sum subarray ending at index i - 1 or by 
            #starting a new subarray from index i
            maxEnding = max(maxEnding + arr[i], arr[i])
            
            # update res if max subarray sum ending at index i > res
            res = max(res, maxEnding)
            
        return res    
 

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


def main():
    T = int(input())
    while (T > 0):

        arr = [int(x) for x in input().strip().split()]

        ob = Solution()

        print(ob.maxSubArraySum(arr))
        print("~")
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends