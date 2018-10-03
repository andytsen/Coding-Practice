# Leetcode: https://leetcode.com/problems/super-palindromes/description/
# Andy Tseng

magic = int(10 ** 4.5)

def find_supers(self, L, R):
    L = int(L)
    R = int(R)
    
    for k in range(magic):
        s = str(k)        
        s = s + s[-2::-1]



 
