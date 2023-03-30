class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = [["()"]]
        for _ in range(n-1):
            cur,prev = set(),res[-1]
            for s in prev:
                for i in range(len(s)):
                    cur.add(s[:i]+'()'+s[i:])
            res.append(list(cur))
        return res[-1]