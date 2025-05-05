
class Solution:   
    def peakElement(self,arr):
        # Code here
        #code here
        n = len(arr)
        
        # if there is only one element, then its a peak 
        if n == 1:
            return 0
            
        # check if the first element is a peak
        if arr[0] > arr[1]:
            return 0
            
        # check if the last element is a peak
        if arr[n - 1] > arr[n - 2]:
            return n - 1
            
        #search space for binary search
        lo, hi = 1, n - 2
        
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            
            # if the element at mid is a
            # peak element return mid
            if arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1]:
                return mid
                
            # if next neighbor is greater, the peak
            # element will exist in the right subarry
            if arr[mid] < arr[mid + 1]:
                lo = mid + 1
                
            # otherwise, it will exist in left sub array
            else:
                hi = mid - 1
            



#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())  # Read number of test cases
    for _ in range(t):
        # Read input and split it into a list of integers
        arr = list(map(int, input().split()))
        # Create a Solution object and calculate the result

        index = Solution().peakElement(arr)
        n = len(arr)
        flag = False
        if index < 0 or index >= n:
            flag = False
        else:
            if index == 0 and n == 1:
                flag = True
            elif index == 0 and arr[index] > arr[index + 1]:
                flag = True
            elif index == n - 1 and arr[index] > arr[index - 1]:
                flag = True
            elif index > 0 and index < n - 1 and arr[
                    index - 1] < arr[index] and arr[index] > arr[index + 1]:
                flag = True
            else:
                flag = False

        if flag:
            print("true")
        else:
            print("false")
        print("~")

# } Driver Code Ends