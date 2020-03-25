#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> balanceStack;
    for(char c : s){
        if(c == '(' || c == '[' || c == '{')
            balanceStack.push(c);
        else if(!balanceStack.empty() && (balanceStack.top() == '(' && c == ')' ||
        balanceStack.top() == '{' && c == '}' || balanceStack.top() == '[' && c == ']'))
            balanceStack.pop();
        else return "NO";
    }
    if(!balanceStack.empty()) return "NO";
    return "YES";
}
