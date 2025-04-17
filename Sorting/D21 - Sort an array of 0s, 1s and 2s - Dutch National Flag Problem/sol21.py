#{ 
 # Driver Code Starts

# } Driver Code Ends

class Solution:
    # Function to sort an array of 0s, 1s, and 2s
    def sort012(self, arr):
        # code here
        n = len(arr)
        lo = 0 
        hi = n - 1
        mid = 0
        
        # Iterate till all the elements are sorted
        while mid <= hi:
            if arr[mid] == 0:
                arr[lo], arr[mid] = arr[mid], arr[lo]
                lo = lo + 1
                mid = mid + 1
                
            elif arr[mid] == 1:
                mid = mid + 1
                    
            else:
                arr[mid], arr[hi] = arr[hi], arr[mid]
                hi = hi - 1
                    
        return arr        


#{ 
 # Driver Code Starts.
def main():
    t = int(input().strip())  # Read the number of test cases
    ob = Solution()

    while t > 0:
        t -= 1
        arr = list(map(int,
                       input().strip().split())
                   )  # Read the array as space-separated integers
        ob.sort012(arr)  # Sort the array

        print(' '.join(map(str, arr)))  # Print the sorted array
        print("~")
        
if __name__ == "__main__":
    main()

# } Driver Code Ends