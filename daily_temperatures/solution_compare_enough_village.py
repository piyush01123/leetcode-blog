class Solution(object):
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        out = [0]*len(T)
        Stack = []
        for i in range(len(T)):
            temp = T[i]
            while len(Stack) > 0:
                oldIndex = Stack[-1]
                if temp > T[oldIndex]:
                    out[oldIndex] = i-oldIndex
                    Stack.pop()
                else:
                    break                        
            Stack.append(i)
        return out    