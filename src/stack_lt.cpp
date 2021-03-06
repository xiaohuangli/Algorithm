//
// Created by xhl on 2021/5/3.
//

#include "stack_lt.h"

int StackLt::longestValidParentheses(string s) {
    stack<int> stack;
    for (int i = 0; i < s.length(); i++) {
        if (stack.empty() || s[i] == '(' || s[stack.top()] == ')') {
            stack.push(i);
        } else {
            stack.pop();
        }
    }

    int max_len = 0;
    int last = s.length();
    while(stack.empty() == false) {
        int cur = last - stack.top() - 1;
        max_len = std::max(cur, max_len);
        last = stack.top();
        stack.pop();
    }
    return std::max(last, max_len);
}

int StackLt::test_longestValidParentheses() {
    string str = ")()((()())";
    int len = StackLt::longestValidParentheses(str);
    cout << "len: " << len << endl;
    return 0;
}

