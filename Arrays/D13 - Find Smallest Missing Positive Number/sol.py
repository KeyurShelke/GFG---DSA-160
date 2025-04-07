#User function Template for python3

class Solution:
    
    #Function to find the smallest positive number missing from the array.
    def missingNumber(self,arr):
        #Your code here
        n = len(arr)
        for i in range(n):
            
            # for arr[i] is within the range 1 to n 
            # and arr[i] is not placed at (arr[i] - 1)th index in arr
            while 1 <= arr[i]  <= n and arr[i] != arr[arr[i] - 1]:
                
                #then swap arr[i] and arr[arr[i] - 1] to place arr[i]
                # to its corresponding index
                temp = arr[i]
                arr[i] = arr[arr[i] - 1]
                arr[temp - 1] = temp
                
        #if any number is not at its coressponding index, then it
        # is the missing number
        for i in range(1, n + 1):
            if i != arr[i - 1]:
                return i
                
                
        # if all number from 1 to n are present
        #then n + 1 is smallest missing number
        return n + 1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


def main():
    T = int(input())

    while (T > 0):
        arr = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.missingNumber(arr))
        print("~")
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends