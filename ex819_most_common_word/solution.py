class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        paragraph = paragraph.lower()
        
        puncs = "!?',;.'"
        for punc in puncs:
            paragraph = paragraph.replace(punc, ' ')
            
        words = [word for word in paragraph.split(' ') if word]
        banned_words = set(banned)
        
        word_counts = collections.defaultdict(int)
        for word in words:
            word_counts[word] += 1
        
        max_word, max_count = None, -1
        for word, count in word_counts.iteritems():
            if count > max_count and word not in banned_words:
                max_word = word
                max_count = count
                
        return max_word