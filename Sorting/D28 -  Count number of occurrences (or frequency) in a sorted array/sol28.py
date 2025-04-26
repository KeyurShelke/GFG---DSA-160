def lower_bound(arr, target):
    res = len(arr)
    lo, hi = 0, len(arr) - 1
    
    while lo <= hi:
        mid = lo + (hi -lo) // 2
        if arr[mid] >= target:
            res = mid
            hi = mid - 1
        else:
            lo = mid + 1
            
    return res
    
def upper_bound(arr, target):
    res = len(arr)
    lo, hi = 0, len(arr) - 1
    
    while lo <= hi:
        mid = lo + (hi -lo) // 2
        if arr[mid] > target:
            res = mid
            hi = mid - 1
        else:
            lo = mid + 1
            
    return res     

class Solution:
    def countFreq(self, arr, target):
        #code here
        return upper_bound(arr, target) - lower_bound(arr, target)


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import bisect
#Main
if __name__ == '__main__':
    t = int(input())
    while t:
        t -= 1
        A = [int(x) for x in input().strip().split()]
        nd = [int(x) for x in input().strip().split()]
        D = nd[0]
        ob = Solution()
        ans = ob.countFreq(A, D)
        print(ans)
        print("~")

# } Driver Code Ends