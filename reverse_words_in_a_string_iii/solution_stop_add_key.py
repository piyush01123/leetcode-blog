class Solution:
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        # just for the record the 1 line below does the job too
        # return " ".join(x[::-1] for x in s.split(" "))
        t = []
        i = 0
        y = ""
        while i<len(s):
            j = i
            word = []
            while j< len(s) and s[j] != " ":
                word.append(s[j])
                j = j+1
            # print(word, i, j)
            x = ""
            for pos in range(j-1, i-1, -1):
                # print(s[pos])
                x = x+s[pos]
            y = y + x + " "
            i = j+1
        return y[:-1]
