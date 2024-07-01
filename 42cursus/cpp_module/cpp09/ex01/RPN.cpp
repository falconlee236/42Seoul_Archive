#include "RPN.hpp"

bool cal(std::string str){
    std::stack<double> stk;
    for(unsigned long i = 0; i < str.length(); i++){
        char c = str[i];
        if (isdigit(c))
            stk.push((double)(c - '0'));
        else if (c == ' ')
            continue;
        else if (c == '+'){
            if (stk.size() < 2)
                return false;
            double a = stk.top();
            stk.pop();
            double b = stk.top();
            stk.pop();
            stk.push(b + a);
        } 
        else if (c == '-') {
            if (stk.size() < 2)
                return false;
            double a = stk.top();
            stk.pop();
            double b = stk.top();
            stk.pop();
            stk.push(b - a);
        }
        else if (c == '*') {
            if (stk.size() < 2)
                return false;
            double a = stk.top();
            stk.pop();
            double b = stk.top();
            stk.pop();
            stk.push(b * a);
        }
        else if (c == '/') {
            if (stk.size() < 2)
                return false;
            double a = stk.top();
            stk.pop();
            double b = stk.top();
            stk.pop();
            stk.push(b / a);
        }
        else 
            return false;
    }
    if (stk.size() != 1)
        return false;
    std::cout << stk.top() << "\n";
    return true;
}