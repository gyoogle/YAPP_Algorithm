#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> c_stack;

    for(string::iterator it = s.begin() ; it != s.end() ; it ++){
        if(c_stack.empty()){
            c_stack.push(*it);
        }
        else{
            if(c_stack.top() != *it){
                c_stack.push(*it);
            }
            else{
                c_stack.pop();
            }
        }
    }

    return c_stack.empty() ? 1 : 0;
}
