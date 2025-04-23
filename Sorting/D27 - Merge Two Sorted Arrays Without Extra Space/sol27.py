class Solution:
    def mergeArrays(self, a, b):
        # code here
        n = len(a)
        m = len(b)
        gap = (n + m + 1) // 2
        
        while gap > 0:
            i = 0
            j = gap
            
            while j < n + m:
                
                # if both pointers are in the first array a[]
                if j < n and  a[i] > a[j]:
                    a[i], a[j] = a[j], a[i]
                    
                # if first pointer is in a[] and
                #the second pointer is in b[]
                elif i < n and j >= n and a[i] > b[j - n]:
                    a[i], b[j - n] = b[j - n], a[i]
                    
                #both pointers are int the second array b
                elif i >= n and b[i - n] > b[j - n]:
                    b[i - n], b[j - n] = b[j - n],b[i - n]
                i += 1
                j += 1
                
            #after operating for gap of 1 break the loop
            if gap == 1:
                break
         
                
            #Calculate the next gap
            gap = (gap + 1) // 2
                
               
                 

                


#{ 
 # Driver Code Starts
# Input handling and main function
if __name__ == "__main__":
    # Number of test cases
    t = int(input().strip())

    for _ in range(t):
        # Input first array
        a = list(map(int, input().strip().split()))
        # Input second array
        b = list(map(int, input().strip().split()))

        # Create solution object and merge the arrays
        solution = Solution()
        solution.mergeArrays(a, b)

        # Output both arrays in the same line space-separated
        print(" ".join(map(str, a)))
        print(" ".join(map(str, b)))

        print("~")

# } Driver Code Ends