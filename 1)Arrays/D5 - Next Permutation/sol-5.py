#User function Template for python3

class Solution:
    def nextPermutation(self, arr):
        # code here
        n = len(arr)
        
        # Find the pivot index
        pivot = -1
        for i in range(n - 2, -1, -1):
            if arr[i] < arr[i + 1]:
                pivot = i
                break
            
        # if pivot point does not exits,
        # reverse  the whole array
        if pivot == -1:
            arr.reverse()
            return
        
        #find the element from the right
        # that is greater than pivot
        for i in range(n - 1, pivot, -1):
            if arr[i] > arr[pivot]:
                arr[i], arr[pivot] = arr[pivot], arr[i]
                break
            
        # reverse the elements from pivot + 1 to the end in place
        left, right = pivot + 1, n - 1
        while left < right:
            arr[left], arr[right] = arr[right], arr[left]
            left += 1
            right -= 1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = input().split()
        N = len(arr)
        for i in range(N):
            arr[i] = int(arr[i])

        ob = Solution()
        ob.nextPermutation(arr)
        for i in range(N):
            print(arr[i], end=" ")
        print()

# } Driver Code Ends