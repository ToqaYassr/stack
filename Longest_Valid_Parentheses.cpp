#include "stack.cpp"
int Longest_Valid_Parentheses(string str) {
    stack<char> stk;
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            stk.push(str[i]);
        } else if (str[i] == ')') {
            if (!stk.isEmpty()) {
                stk.pop();
                num += 2;
            }
        }
    }
    return num;
}
