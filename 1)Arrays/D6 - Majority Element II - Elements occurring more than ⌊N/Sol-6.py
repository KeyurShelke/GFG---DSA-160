class Solution:
    # Function to find the majority elements in the array
    def findMajority(self, arr):
        #Your Code goes here.
        n = len(arr)
        
        # Initialize two candidates & their counts
        ele1, ele2 = -1,-1
        cnt1, cnt2 = 0, 0
        
        for ele in arr:
            # increment count for candidate 1
            if ele1 == ele:
                cnt1 += 1
            #   increment count for candidate 2
            elif ele2 == ele:
                cnt2 += 1
            # New candidate 1 if count is zero 
            elif cnt1 == 0:
                ele1 = ele
                cnt1 += 1
            # New candidate 2 if count is zero 
            elif cnt2 == 0:
                ele2 = ele
                cnt2 += 1
            # Decrease counts if neither candidate
            else:
                cnt1 -= 1
                cnt2 -= 1
                
        res = []
        cnt1, cnt2 = 0, 0
        
        #Count the occurrences of candidates
        for ele in arr:
            if ele1 == ele:
                cnt1 += 1
            if ele2 == ele:
                cnt2 += 1
                
        #add to result if they are majority elements
        if cnt1 > n / 3:
            res.append(ele1)
        if cnt2 > n / 3 and ele1 != ele2:
            res.append(ele2)
            
        if len(res) == 2 and res[0] > res[1]:
            res[0], res[1] =  res[1], res[0]
            
        return res
        
                


#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        nums = list(map(int, s.split()))
        ob = Solution()
        ans = ob.findMajority(nums)
        if not ans:
            print("[]")
        else:
            print(" ".join(map(str, ans)))


if __name__ == "__main__":
    main()

# } Driver Code Ends