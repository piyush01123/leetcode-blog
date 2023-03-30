def isfloat(s):
    try:
        float(s)
        return True
    except:
        return False

class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        words = sentence.split(' ')
        n = len(words)
        adict,alist = {},[]
        for i,w in enumerate(words):
            if w.startswith('$') and isfloat(w[1:]) and float(w[1:])>=0:
                w = w[1:]
                w = float(w)*(100-discount)/100
                w = "${:.2f}".format(w)
            adict[i] = w
        for i in range(n):
            alist.append(adict[i])
        return ' '.join(alist)