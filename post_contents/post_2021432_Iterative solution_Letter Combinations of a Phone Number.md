# Method:
Create a string array. In the beginning it has only one member which is empty string. Then when you see a digit, create a new array which is each member of old array plus each letter of new digit. Then replace the old array with the new one. Then go to next digit and so on.
Example:
Input: "23"
Array in the process:
```
start=> [""]
digit="2"=> ["a", "b", "c"]
digit="3"=> ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
```

c++:
```
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) return {};
        unordered_map<char,vector<char>> mapping;
        mapping["2"]={"a","b","c"};
        mapping["3"]={"d","e","f"};
        mapping["4"]={"g","h","i"};
        mapping["5"]={"j","k","l"};
        mapping["6"]={"m","n","o"};
        mapping["7"]={"p","q","r","s"};
        mapping["8"]={"t","u","v"};
        mapping["9"]={"w","x","y","z"};
        vector<string>words {""};
        for (char digit: digits)
        {
            vector<string> new_words;
            for (string word: words)
                for (char letter: mapping[digit])
                    new_words.push_back(word+letter);
            words=new_words;
        }
        return words;
    }
};
```

python:
```
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0: return []
        mapping = {"2": "abc", "3": "def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs", "8":"tuv", "9":"wxyz"}
        words = [""]
        for digit in digits:
            letters = mapping[digit]
            new_words = []
            for word in words:
                for letter in letters:
                    new_words.append(word+letter)
            words = new_words
        return words
```