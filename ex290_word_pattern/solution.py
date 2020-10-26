class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        split = s.split(' ')
        if len(split) != len(pattern):
            return False
        
        mapped_words = set([])
        word_map = {}
        for pattern_character, word in zip(pattern, split):
            mapped_word = word_map.get(pattern_character, None)
            already_used = word in mapped_words
            if mapped_word is None and already_used is False:
                word_map[pattern_character] = word
                mapped_words.add(word)
            elif mapped_word != word:
                return False
            
        return True
                
