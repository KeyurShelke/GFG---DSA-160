#User function Template for python3

class Solution:
    #Function to rotate an array by d elements in counter-clockwise direction. 
    def rotateArr(self, arr, d):
        #Your code here
        n = len(arr)
        
        # handle if d > size of array
        d %= n
        
        # Reverse the first d elements
        reverse(arr, 0, d - 1)
        
        #reverse the remaining n - d elements
        reverse(arr, d, n - 1)
        
        #reverse the entire array
        reverse(arr, 0, n - 1)
        
# Function to reverse a portion of the array
def reverse(arr, start, end):
    while start <  end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1
        