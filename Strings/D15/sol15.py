#User function Template for python3
def trimLeadingZeros(s):
    
    #find the position of the first '1'
    firstOne = s.find('1')
    return s[firstOne:] if firstOne != -1 else "0"
    
class Solution:
	def addBinary(self, s1, s2):
		# code here
		
		# Trim Leading Zeros
		s1 = trimLeadingZeros(s1)
		s2 = trimLeadingZeros(s2)
		
		n = len(s1)
		m = len(s2)
		
		# swap the strings if s1 is of smaller lenght
		if n < m:
			s1, s2 = s2, s1
			n, m = m, n
		    
		j  = m - 1
		carry = 0
		result = []
		
		# Transverse both string from the end
		for i in range(n - 1, -1, -1):
		    
		    # Current bit os s1
			bit1 = int(s1[i])
			bitSum = bit1 + carry
		    
		    # if there are remaining bits in s2
		    # add them to the bitSum
			if j >= 0:
		        # Current bit of s2
				bit2 = int(s2[j])
				bitSum += bit2
				j -= 1
		        
		     #calculate the result bit and update carry
			bit = bitSum % 2
			carry = bitSum // 2
		     
		     # Update the current bit in result
			result.append(str(bit))
		     
		     
		    
        # If there's any carry left, prepend it to the result	
			if carry > 0:
				result.append('1')
            
		return ''.join(result[::-1])    

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        a = input().strip()
        b = input().strip()
        ob = Solution()
        answer = ob.addBinary(a, b)

        print(answer)
        print("~")

# } Driver Code Ends