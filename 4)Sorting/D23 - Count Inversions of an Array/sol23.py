def countAndMerge(arr, l, m, r):
    
    #counts in two subarrays
    n1 = m - l + 1
    n2 = r - m
        
    #set up two lists for left and right halves
    left = arr[l:m + 1]
    right = arr[m + 1:r + 1]
        
    # initailaize inversion count(or result) and merge two halves
    res = 0
    i = 0
    j = 0
    k = l
    while i < n1 and j < n2:
        
        # No increment in inversion count
        #if left[] has a smaller or equal element
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
                
        else:
            arr[k] = right[j]
            j += 1
            res += (n1 - i)
        k += 1    
        
    # merge remaining elements
    while i < n1:
        arr[k] = left[i]
        i += 1
        k += 1
    while j < n2:
        arr[k] = right[j]
        j += 1
        k += 1
            
    return res
def countInv(arr, l, r):
    res = 0
    if l < r:
        m = (r + l) // 2
            
        #Recursively count inversions
        # in the left and right jalves
        res += countInv(arr, l, m)
        res += countInv(arr, m + 1, r)
            
        #Count inversions such that greater element is in
        # the left half and smaller in the right half
        res += countAndMerge(arr, l, m, r)
    return res    

class Solution:
    #User function Template for python3
    #Function to count inversions in the array.
    def inversionCount(self, arr):
        # Your Code Here        
        return countInv(arr, 0, len(arr) - 1)

            

       


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        a = list(map(int, input().strip().split()))
        obj = Solution()
        print(obj.inversionCount(a))
        print("~")

# } Driver Code Ends