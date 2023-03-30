def isfloat(s):
    try:
        float(s)
        return True
    except:
        return False

class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        words = sentence.split(' ')
        for i,w in enumerate(words):
            if w.startswith('$') and isfloat(w[1:]) and float(w[1:])>=0:
                w = "${:.2f}".format(float(w[1:])*(100-discount)/100)
            words[i] = w
        return ' '.join(words)