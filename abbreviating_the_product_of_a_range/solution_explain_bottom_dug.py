class Solution:
    def abbreviateProduct(self, left: int, right: int) -> str:
        P = 1
        for num in range(left,right+1):
            P *= num
        S = str(P)
        ctr = 0
        for i in range(len(S)-1,-1,-1):
            if S[i]!='0':
                break
            ctr += 1
        if len(S[:i+1])>10:
            S_dash = S[:i+1][:5]+"..."+S[:i+1][-5:]
        else:
            S_dash = S[:i+1]
        return S_dash + 'e'+str(ctr)