
    
def computeLPSArray(pat):
    n = len(pat)
    lps = [0] * n
    
    #lps[0] is always 0
    len_lps = 0 
    
    # loop calculates lps[i] for i = 1 to n -1
    i = 1
    while i < n:
        
    # if  the character match, increment  len and set lps[i]
        if pat[i] == pat[len_lps]:
            len_lps += 1
            lps[i] = len_lps
            i += 1
    
            
    # if there is a mismatch
        else:
            
    # if len is not zero, update len to the last known prefix lenght
            if len_lps != 0:
                len_lps = lps[len_lps - 1]
                
        # No prefix matches, set lps [i] to 0
            else:
                lps[i] = 0
                i += 1
    
    return lps
                
class Solution:    
        
    def minChar(self, s):
    
    #Write your code here
        n = len(s)
        rev = s[::-1]
        
    #   get cancatenarion of string,special char and reverse string
        s = s + "$" + rev
        
        lps = computeLPSArray(s)
        
    #by  substracting last entry of lps array from 
    # string length, we will get our result 
        return n - lps[-1]
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        s = input()
        obj = Solution()
        ans = obj.minChar(s)
        print(ans)
        print("~")

# } Driver Code Ends