#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends

#User function Template for python3
class Solution:
    def minRemoval(self, intervals):
        # Code here
        cnt = 0
        
        #sort by minimum starting point
        intervals.sort(key=lambda x: x[0])
        
        end = intervals[0][1]
        for i in range(1, len(intervals)):
            
            #if the current starting point is less than
            #the previous interval's ending point
            #(ie. there is an overlap)
            if intervals[i][0] < end:
                
                #Increase cnt and remove the interval
                # with the higher ending point
                cnt += 1
                end = min(intervals[i][1], end)
                
            else:
                end = intervals[i][1]
        
        return cnt
#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N = int(input())
        intervals = [list(map(int, input().split())) for i in range(N)]
        ob = Solution()
        res = ob.minRemoval(intervals)
        print(res)
        print("~")
# } Driver Code Ends