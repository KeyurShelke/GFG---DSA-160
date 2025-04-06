#User function Template for python3

#Complete this function
#Function to find maximum circular subarray sum.
def circularSubarraySum(arr):
    ##Your code here
    totalSum = 0 
    currMaxSum = 0
    currMinSum = 0
    maxSum = arr[0]
    minSum = arr[0]
    
    for i in range(len(arr)):
        
        # Kadane's to find maximum sum subarray
        currMaxSum = max(currMaxSum + arr[i], arr[i])
        maxSum = max(maxSum, currMaxSum)
        
        # Kadane's to find minimum sum subarray
        currMinSum = min(currMinSum + arr[i], arr[i])
        minSum = min(minSum, currMinSum)
        
        # sum of all the elements of input array
        totalSum += arr[i]
        
    normalSum = maxSum 
    circularSum  = totalSum - minSum
    
    # If the minimum subarray is equal to total Sum
    # then we Just need to return normalSum
    if minSum == totalSum:
        return normalSum
        
    return max(normalSum, circularSum)    
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math
import sys

if __name__ == "__main__":
    T = int(input())
    while (T > 0):

        arr = [int(x) for x in input().strip().split()]

        print(circularSubarraySum(arr))

        T -= 1
        print("~")

# } Driver Code Ends