class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        alphabet = "abcdefghijklmnopqrstuvwxyz"
        alphabet_dict = {v:k for k,v in enumerate(alphabet)}
        n1 = int(''.join([str(alphabet_dict[letter]) for letter in firstWord]))
        n2 = int(''.join([str(alphabet_dict[letter]) for letter in secondWord]))
        n3 = int(''.join([str(alphabet_dict[letter]) for letter in targetWord]))
        return n1+n2==n3

        