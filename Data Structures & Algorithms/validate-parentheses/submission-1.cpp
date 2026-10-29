class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char c : s)
        {
            if (c == '[' || c == '{' || c == '(')
                stack.push_back(c);
            if (c == ']' || c == '}' || c == ')') {
                if (stack.size() == 0) 
                    return false;
                if (c == ']' && stack.back() != '[')
                    return false;
                if (c == '}' && stack.back() != '{')
                    return false;
                if (c == ')' && stack.back() != '(')
                    return false;
                stack.pop_back();
            }
        }
        return stack.size() == 0;
    }
};
