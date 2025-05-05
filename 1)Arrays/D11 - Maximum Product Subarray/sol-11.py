#User function Template for python3
class Solution:

	# Function to find maximum
	# product subarray
	def maxProduct(self,arr):
		# code here
		n = len(arr)
		
		# max product ending at current index
		currMax = arr[0]
		
		# min product ending at current index
		currMin = arr[0]
		
		# initialize overall max product
		maxProd = arr[0]
		
		# iterate through the array
	for i in range(1, n):
		    
		    # Temporary variable to store the maximum product ending
		    # at the current index
		    temp = max(arr[i], arr[i] * currMax, arr[i] * currMin) 
		   
		   # Update  the minimum product ending at the current index 
            currMin = min(arr[i], arr[i] * currMax, arr[i] * currMin) 
		   
		   # Update the maximum product ending at the current index 
		    currMax = temp
		   
		   # Update the overall maximum product
		    maxProd = max(maxProd, currMax)
		   
        return maxProd	   
		   
		
		


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.maxProduct(arr)
        print(ans)
        tc -= 1

# } Driver Code Ends