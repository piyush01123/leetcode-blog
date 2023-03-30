class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for char in s:
            if char in "({[":
                stack.append(char)
            elif char in ")}]":
                b1 = char==')' and stack and stack[-1]=='('
                b2 = char=='}' and stack and stack[-1]=='{'
                b3 = char==']' and stack and stack[-1]=='['
                if b1 or b2 or b3:
                    stack.pop()
                else:
                    return False
            else:
                raise ValueError("Invalid Character")
        return len(stack)==0