class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char ch: s)
        {
            if (ch=='('||ch=='{'||ch=='[') stack.push_back(ch);
            else 
            {
                if (ch==')')
                {
                    if (stack.size()==0 || stack.back()!='(') return false;
                    stack.pop_back();
                }

                if (ch=='}')
                {
                    if (stack.size()==0 || stack.back()!='{') return false;
                    stack.pop_back();
                }

                if (ch==']')
                {
                    if (stack.size()==0 || stack.back()!='[') return false;
                    stack.pop_back();
                }
            }
        }
        return stack.size()==0;
    }
};