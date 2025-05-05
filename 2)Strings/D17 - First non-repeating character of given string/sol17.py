# as rthe input string can only have lowercase
#characters, the maximum characters will be 26
MAX_CHAR = 26

class Solution:
    def nonRepeatingChar(self,s):
        #code here
        vis = [-1] * MAX_CHAR
        
        #integrate the string
        for i in range(len(s)):
            
            #if the character is seen for the first time,
            #store its index
            if vis[ord(s[i]) - ord('a')] == -1:
                vis[ord(s[i]) - ord('a')] = i
                
            #if the character is seen again, mark it as -2
            else:
                vis[ord(s[i]) - ord('a')] = -2
        idx = float('inf')
        
        #find the smallest index amongest all non-reapeating characters
        for i in range(MAX_CHAR):
            if vis[i] >= 0:
                idx = min(idx, vis[i])
                
        #if non-repeating character is found, return it
        #else return $
        return '$' if idx == float('inf') else s[idx]
            
                
                
    
    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = str(input())
        obj = Solution()
        ans = obj.nonRepeatingChar(s)
        if (ans != '$'):
            print(ans)
        else:
            print(-1)

        print("~")

# } Driver Code Ends