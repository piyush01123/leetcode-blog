class Solution:
    def maxValue(self, n: str, x: int) -> str:
        b=0
        if int(n)>0:
            for i, digit in enumerate(n):
                if int(digit)<x:
                    b=1
                    break
            # print("IB", i, b, len(n))
            if i==len(n)-1 and b==0:
                i+=1
            # print("final i", i)
            return n[:i]+str(x)+n[i:]
        else:
            n = str(-1*int(n))
            for i, digit in enumerate(n):
                if int(digit)>x:
                    b=1
                    break
            # print("IB", i, b, len(n))
            if i==len(n)-1 and b==0:
                i+=1
            # print("final i", i)
            return '-'+n[:i]+str(x)+n[i:]

