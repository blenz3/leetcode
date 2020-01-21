class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        ALPHABET = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        ALPHABET_LENGTH = len(ALPHABET)
        ALPHABET_MAP = dict((i + 1, c) for i, c in enumerate(ALPHABET))
        
        column_title = ''
        while n > 0:
            digit = n % ALPHABET_LENGTH
            if digit == 0:
                column_title = ALPHABET_MAP[ALPHABET_LENGTH] + column_title
                n = (n / ALPHABET_LENGTH) - 1
            else:
                column_title = ALPHABET_MAP[digit] + column_title
                n /= ALPHABET_LENGTH
                
        return column_title
            
        
