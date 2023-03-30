class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        answer = [False for _ in range(len(s)+1)]
        answer[0] = True
        for i in range(1, len(s)+1):
            curr = False
            for j in range(i):
                if answer[j] and s[j:i] in wordDict:
                    curr = True
            answer[i] = curr
            # print(i,answer[:i+1])
        return answer[-1]