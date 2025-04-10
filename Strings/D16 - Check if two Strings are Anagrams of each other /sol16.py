#User function Template for python3


class Solution:
    
    #Function is to check whether two strings are anagram of each other or not.
    def areAnagrams(self, s1, s2):
        #code here
        
        #create a hashmap to store character frequencies
        charCount ={}
        
        #count frequency of each character in string s1
        for ch in s1:
            charCount[ch] = charCount.get(ch, 0) + 1
            
        # count frequency of each charecter in string s2
        for ch in s2:
            charCount[ch] = charCount.get(ch, 0) - 1
            
        #ccheck if all frequencies are zero
        for value in charCount.values():
            if value != 0:
                return False
                
        #check if all frequencies satiesfied, they are anagrams
        return True


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        a = input().strip()
        b = input().strip()
        if (Solution().areAnagrams(a, b)):
            print("true")
        else:
            print("false")
        print("~")

# } Driver Code Ends