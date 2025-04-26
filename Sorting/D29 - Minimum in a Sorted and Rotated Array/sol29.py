#User function Template for python3

class Solution:
    def findMin(self, arr):
        #complete the function here
        lo, hi = 0, len(arr) - 1
        
        while lo < hi:
            
            # The current subarry is already sorted,
            # the ,minimum is at the low idex
            if arr[lo] < arr[hi]:
                return arr[lo]
            
            # We reach here when we have at least two elements and the current subarray is roated
        
            mid = (lo + hi) // 2
        
            #the right half is not sorted. So the minimum element must br in the right half
        
            if arr[mid] > arr[hi]:
                lo = mid + 1
            
            # The right half is sorted.Note that in this case,we do not change high to mid - 1 but 
            #keep it to mid. As the mid element itsels can be the smallest
            else:
                hi = mid
            
        return arr[lo]    
        


#{ 
 # Driver Code Starts
def main():
    T = int(input())

    while T > 0:
        a = list(map(
            int,
            input().strip().split()))  # Convert input to list of integers
        print(Solution().findMin(a))  # Call findMin with the array 'a'
        T -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends