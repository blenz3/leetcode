class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return 0  
        
        # Use a sieve of eratosthenes strategy
        primes = [False, False] + [True for _ in range(n - 2)]
        for i in range(2, n):
            # This is already a composite number
            if not primes[i]:
                continue
            
            # Mark all multiples of this number as not prime
            for j in range(i + i, n, i):
                primes[j] = False
                
        return len([x for x in primes if x])
        
