#User function Template for python3

class Solution:
    def search(self,arr,key):
        # Complete this function
       low = 0 
       high = len(arr) - 1
       
       while low <= high:
           
           mid  = low + (high - low) // 2
           
           
           if arr[mid] == key:
               return mid
               
           if arr[mid] >= arr[low]:
                
                if key >= arr[low] and key < arr[mid]:
                    high = mid - 1
                    
                else:
                    low = mid + 1
                    
           else:
                
                if key > arr[mid] and key <= arr[high]:
                    low = mid + 1
                else:
                    high = mid - 1
                    
       return -1            


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        A = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.search(A, k))
        print("~")

# } Driver Code Ends