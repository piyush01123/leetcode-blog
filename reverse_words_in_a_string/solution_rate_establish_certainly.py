class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = []
        start = 0
        end = 0
        # print(len(s), 'lenght')
        for i in range(len(s)):
            char = s[i]
            # print(char, start, end)
            if char == ' ':
                if end > start:
                    words.append(s[start:end])
                start = end = i+1
            else:
                end += 1
        words.append(s[start:end])
        # print(words)
        rev_words = []
        for i in range(len(words)):
            if len(words[-1-i])>0:
                rev_words.append(words[-1-i])
        # print(rev_words)
        # return ' '.join(rev_words)
        if len(rev_words) == 1:
            return rev_words[0]
        else:
            return ' '.join(rev_words)
