#User function Template for python3

def computeLPSArray(pat):
    n = len(pat)
    lps = [0] * n
    
    #length of the previous longest prefix suffix
    patLen = 0
    
    # loop calculates lps[i] for i = 1 to n-1
    i = 1
    while i < n:
        
        #if the characters match, increment len and extend the matchin prefix
        if pat[i] == pat[patLen]:
            patLen += 1
            lps[i] = patLen
            i += 1
            
        # if there is a mismatch
        else:
            
            #if ken is not zero, update len t last known prefix length
            if patLen != 0:
                patLen = lps[patLen - 1]
                
            # No prefix matches, set lps[i] = 0 
            # and move to the next character
            else:
                lps[i] = 0
                i += 1
                
    return lps

class Solution:
    
    #Function to check if two strings are rotations of each other or not.
    def areRotations(self,s1,s2):
        #code here
        txt = s1 +s1
        pat = s2
        
        # search the pattern strings2 in the concatenation string 
        n = len(txt)
        m = len(pat)
        
        # Create lps[] that will hold the longest prefix suffix
        # values for pattern
        lps = computeLPSArray(pat)
        
        i = 0
        j = 0
        while i < n:
            if pat[j] == txt[i]:
                j += 1
                i += 1
                
            if j == m:
                return True
                
            # Mismatch after j matches
            elif i < n and pat[j] != txt[i]:
                
                #do not match lps[0...lps[j-1]] characters,they will match anyway
                if  j != 0:
                    j = lps[j-1]
                else:
                    i += 1
                    
        return False            
                    


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
        s1 = str(input())
        s2 = str(input())
        if (Solution().areRotations(s1, s2)):
            print("true")
        else:
            print("false")

# } Driver Code Ends