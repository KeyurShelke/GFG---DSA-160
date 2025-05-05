#User function Template for python3
class Solution:
    # Function to find hIndex
    def hIndex(self, citations):
        #code here
        n = len(citations)
        freq = [0] * (n + 1)
        
        #count the frequency of citations
        for citation in citations:
            if citation >= n:
                freq[n] += 1
            else:
                freq[citation] += 1
                
        idx = n 
        
        # Variable to keep track of the count of papers
        # having at least idx citations
        s = freq[n]
        while s < idx:
            idx -= 1
            s += freq[idx]
            
        # return the largest index for which the count of 
        # papers with at least idx citations becames >= idx
        return idx


#{ 
 # Driver Code Starts
# Initial Template for Python 3

# Main
if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        arr = [int(x) for x in input().strip().split()]

        ob = Solution()
        result = ob.hIndex(arr)

        print(result)
        print("~")

# } Driver Code Ends