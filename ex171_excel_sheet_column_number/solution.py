class Solution(object):
    
    ALPHABET = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    CHARACTER_VALUES = dict((char, i + 1) for i, char in enumerate(ALPHABET))
    
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        character_index = 0
        for i in range(len(s)):
            order_of_magnitude = 26 ** i
            character_index += (order_of_magnitude * Solution.CHARACTER_VALUES[s[len(s) - i - 1]])
        
        return character_index
        
