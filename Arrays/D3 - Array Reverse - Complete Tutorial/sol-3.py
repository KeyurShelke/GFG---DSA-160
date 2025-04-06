class Solution:
    def reverseArray(self, arr):
        # code here
        left = 0
        right = len(arr) - 1
        
        #Iterate till left is less than right
        while left < right:
            
            #swap elements of left & right posotion
            arr[left], arr[right] = arr[right], arr[left]
            
            #increment  - left pointer
            left += 1
            
            #decrement  - right pointer
            right -= 1
        return arr    
        
    