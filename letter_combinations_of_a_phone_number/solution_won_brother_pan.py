class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0: return []
        mapping = {'2': 'abc', '3': 'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        words = [""]
        for digit in digits:
            letters = mapping[digit]
            new_words = []
            for word in words:
                for letter in letters:
                    new_words.append(word+letter)
            words = new_words
        return words
        