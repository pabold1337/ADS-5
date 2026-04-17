// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> stack;
    std::string result;

    for (size_t i = 0; i < inf.length(); i++) {
        char c = inf[i];

        if (isdigit(c)) {
            while (i < inf.length() && isdigit(inf[i])) {
                result += inf[i];
                i++;
            }
            result += ' ';
            i--;
        }
        else if (c == '(') {
            stack.push(c);
        }
        else if (c == ')') {
            while (!stack.isEmpty() && stack.get() != '(') {
                result += stack.pop();
                result += ' ';
            }
            if (!stack.isEmpty() && stack.get() == '(') {
                stack.pop();
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int priority = (c == '+' || c == '-') ? 1 : 2;
            while (!stack.isEmpty() && stack.get() != '(') {
                char top = stack.get();
                int topPriority = (top == '+' || top == '-') ? 1 : 2;
                if (topPriority >= priority) {
                    result += stack.pop();
                    result += ' ';
                } else {
                    break;
                }
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        result += stack.pop();
        result += ' ';
    }

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

int eval(const std::string& pref) {
    TStack<int, 100> stack;
    std::string num;

    for (size_t i = 0; i < pref.length(); i++) {
        char c = pref[i];

        if (isdigit(c)) {
            num += c;
        }
        else if (c == ' ' && !num.empty()) {
            int number = 0;
            for (char digit : num) {
                number = number * 10 + (digit - '0');
            }
            stack.push(number);
            num.clear();
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = stack.pop();
            int a = stack.pop();
            int res = 0;

            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') res = a / b;

            stack.push(res);
        }
    }

    return stack.pop();
}
