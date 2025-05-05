#User function Template for python3
def constructLps(pat, lps):
    
    #len sores the length of longest prefix which is also a suffix for the previous index
    len_ = 0
    m = len(pat)
    
    
    # lps[0] is always 0
    lps[0] = 0 
    
    i = 1
    while i < m:
        #if characters match, increments the size of lps
        if pat[i] == pat[len_]:
            len_ += 1
            lps[i] = len_
            i += 1
            
        #if there is mismatch
        else:
            if len_ != 0:
                
                #update len to the previous lps value
                # to avoid redundant comparisans
                len_ = lps[len_ - 1]
            else:
                #if no matching prifix found
                lps[i] = 0
                i += 1
                
                
    

class Solution:
    def search(self, pat, txt):
        # code here
        n = len(txt)
        m = len(pat)
        
        lps = [0] * m
        res = []
        constructLps(pat,lps)
        #pointer i and j, for traversing
        # the text and pattern
        i = 0
        j = 0
        
        while i < n:
            #if characters match, move both pointer
            if txt[i] == pat[j]:
                i += 1
                j += 1
                
                # if entire pattern is matched syore the start index in result
                if j == m:
                    res.append(i-j)
                    
                    j = lps[j-1]
                    
            else:
                if j!= 0:
                    j = lps[j-1]
                else:
                    i += 1
                        
        return res                    
                
                    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        patt = input().strip()
        ob = Solution()
        ans = ob.search(patt, s)
        if len(ans) == 0:
            print("[]", end="")
        for value in ans:
            print(value, end=' ')
        print()

# } Driver Code Ends