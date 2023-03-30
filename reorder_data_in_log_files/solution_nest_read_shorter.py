class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letter_logs, digit_logs = [],[]
        for log in logs:
            words = log.split(' ')
            id, s = words[0], ' '.join(words[1:])
            isLetter, isDigit = True,True;
            for ch in s:
                if ch!=' ' and ch not in 'abcdefghijklmnopqrstuvwxyz':
                    isLetter = False
                    break
            for ch in s:
                if ch!=' ' and ch not in '0123456789':
                    isDigit = False
                    break
            if isLetter==isDigit:
                raise ValueError("Some issue with input?")
            if isLetter:
                letter_logs.append((s,id,))
            else:
                digit_logs.append(log)
        letter_logs.sort(key=lambda x: (x[0],x[1]))
        letter_logs = [id+' '+s for s,id in letter_logs]
        return letter_logs+digit_logs