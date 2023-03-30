class Solution:
    def minAddToMakeValid(self, S):
        """
        :type S: str
        :rtype: int
        """
        # Edge case
        if len(S) == 0:
            return 0
        
        Stack = []
        count = 0
        for i in range(len(S)):
            if S[i] == ')':
                if len(Stack) >  0:
                    del Stack[-1]
                else:
                    count += 1                        
            else:
                Stack.append(S[i])
        return count + len(Stack)
