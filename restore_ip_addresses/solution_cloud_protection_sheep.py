class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def valid(s: str)->bool:
            if len(s)==0 or len(s)>3:
                return False
            if len(s)>1 and s[0]=='0':
                return False
            if int(s)>255:
                return False
            return True

        if len(s)<4: return []
        res = []
        for comb in itertools.combinations(range(len(s)+3),3):
            a,b,c = comb
            n1,n2,n3,n4 = s[:a],s[a:b],s[b:c],s[c:]
            if not valid(n1) or not valid(n2) or not valid(n3) or not valid(n4):
                continue
            res.append('{}.{}.{}.{}'.format(n1,n2,n3,n4))
        return res