#User function Template for python3

class Solution:
    def getMinDiff(self, arr,k):
        # code here
        n = len(arr)
        arr.sort()
        
        #if we increase all heights by k or decrease all
        # heights by k, the result will be arr[n -1] - arr[0]
        res = arr[n - 1] - arr[0]
        
        #for all indices i, increment arr[0...i-1] by k and
        #decrease arr[i...n-1] by k
        for i in range(1, len(arr)):
            #impossible to decrement height of the tower ny k,
            # continue to the next tower
            if arr[i] - k < 0:
                continue
            
            #minimum height after modification
            minH = min(arr[0] + k, arr[i] - k)
            
            #minimum height after modification
            maxH = max(arr[i -1] + k, arr[n - 1] - k)
            
            #store the minimum difference as result
            res = min(res, maxH - minH)
            
        return res    

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        k = int(input())
        # n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getMinDiff(arr, k)
        print(ans)
        print("~")
        tc -= 1

# } Driver Code Ends