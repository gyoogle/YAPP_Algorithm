#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool check(string str){
    int lenght = str.length();
    stack<char> stack;
    for(int i = 0; i <lenght; i++){
        char a = str[i];
        if(a == '('){
            stack.push(str[i]);
        }
        else{
            if(!stack.empty()){
                stack.pop();
            }
            else return false;
        }
    }
    return stack.empty();
}
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        if(check(str)){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
        
    }
    return 0;
}