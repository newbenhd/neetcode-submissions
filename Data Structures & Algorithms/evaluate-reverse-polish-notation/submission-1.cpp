class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> store;
        for (string &s :tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int secondOperand = store.back();
                store.pop_back();
                int firstOperand = store.back();
                store.pop_back();
                if (s == "+")
                    store.push_back(firstOperand + secondOperand);
                else if (s == "-")
                    store.push_back(firstOperand - secondOperand);
                else if (s == "*")
                    store.push_back(firstOperand * secondOperand);
                else
                    store.push_back(firstOperand / secondOperand);
            } else {
                store.push_back(stoi(s));
            }
        }
        return store.back();
    }
};
