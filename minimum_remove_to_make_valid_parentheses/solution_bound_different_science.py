class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        ctr = 0
        toRemove = []
        for i, ch in enumerate(s):
            if ch == '(':
                ctr += 1
            if ch == ')':
                if ctr == 0:
                    toRemove.append(i)
                if ctr > 0:
                    ctr -= 1
        if ctr > 0:
            for i in range(len(s)-1,-1,-1):
                if s[i]=='(':
                    toRemove.append(i)
                    ctr -=1
                if ctr==0:
                    break
        return ''.join([s[i] for i in range(len(s)) if i not in toRemove])