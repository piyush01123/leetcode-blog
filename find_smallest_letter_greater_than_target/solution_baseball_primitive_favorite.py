class Solution:
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        letters = [ord(l) for l in letters]
        target = ord(target)
        for letter in letters:
            if letter<=target:
                continue
            else:
                return chr(letter)
        return chr(letters[0])