def recur(letters,times,coll,comb=[]):
    if times==0:
        coll.append(''.join(comb))
        return
    for letter in letters:
        domb = comb.copy()
        domb.append(letter)
        recur(letters,times-1,coll,domb)

def validate(string):
    stack = []
    for char in string:
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
        
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        collection = []
        recur("()", 2*n, collection)
        validItems = []
        for item in collection:
            if validate(item):
                validItems.append(item)
        return validItems
