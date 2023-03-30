class Solution:
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return " ".join([x[::-1] for x in s.split(" ")])
        t = []
        i = 0
        while i<len(s):
            j = i
            word = []
            while j< len(s) and s[j] != " ":
                word.append(s[j])
                j = j+1
            i = j+1
            # print(word)
            t += word[::-1]
            t += " "
        # print(t)
        return "".join(t[:-1])