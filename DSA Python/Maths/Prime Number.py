class Solution:
    def isPrime(self, n):
        if n <= 1:
            return False
        
        for i in range(2, n):   # check all numbers
            if n % i == 0:
                return False
        
        return True
    
    
class Solution:
    def isPrime(self, n):
        if n <= 1:
            return False
        
        i = 2
        while i * i <= n:
            if n % i == 0:
                return False
            i += 1
        
        return True