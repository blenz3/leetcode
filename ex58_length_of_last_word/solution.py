class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        words = filter(bool, s.split(' '))
        return len(words[-1]) if words else 0
        
