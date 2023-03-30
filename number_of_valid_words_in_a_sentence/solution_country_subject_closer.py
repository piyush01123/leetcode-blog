class Solution:
    def countValidWords(self, sentence: str) -> int: 
        words = sentence.split()
        ctr = 0 
        digits = [str(x) for x in list(range(10))]
        alphabet = "abcdefghijklmnopqrstuvwxyz"
        for word in words:
            n = len(word)
            hasDigit = False
            hasPunctuation = False
            hasInvalidHyphen = False
            punctuation_marks = "!.,"
            hyphen_ctr = 0
            for pos, char in enumerate(word):
                if char in digits:
                    hasDigit = True
                if char in punctuation_marks and pos<n-1:
                    hasPunctuation = True
                if char=='-':
                    if pos==0 or pos==n-1:
                        hasInvalidHyphen = True
                    else:
                        if word[pos-1] in alphabet and word[pos+1] in alphabet:
                            hyphen_ctr += 1
                        else:
                            hasInvalidHyphen = True
            if hyphen_ctr>1:
                hasInvalidHyphen = True
            if hasDigit==False and hasPunctuation==False and hasInvalidHyphen==False:
                ctr += 1
        return ctr 