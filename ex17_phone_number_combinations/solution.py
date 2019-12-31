DIGIT_MAP = {
    '2': ['a', 'b', 'c'], 
    '3': ['d', 'e', 'f'],
    '4': ['g', 'h', 'i'], 
    '5': ['j', 'k', 'l'], 
    '6': ['m', 'n', 'o'],         
    '7': ['p', 'r', 'q', 's'], 
    '8': ['t', 'u', 'v'], 
    '9': ['w', 'x', 'y', 'z']
}

class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        combinations = []
        mapped_digits = [DIGIT_MAP[digit] for digit in digits]
        for mapped_characters in mapped_digits:
            if not combinations:
                combinations = mapped_characters
                continue
            
            new_combinations = []
            for character in mapped_characters:
                for combination in combinations:
                    new_combinations.append(combination + character)
                    
            combinations = new_combinations
                    
        return combinations
                
                
                
