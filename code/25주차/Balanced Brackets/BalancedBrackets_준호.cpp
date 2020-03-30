#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> checkStack ;

    for(auto it = s.begin() ; it != s.end() ; it ++){
        if(*it == '(' || *it == '{' || *it == '['){
            checkStack.push(*it);
        }
        else{
            if(checkStack.empty()){
                return "NO";
            }
            else{
                char top = checkStack.top();

                if((*it == ')' && top == '(') ||
                    (*it == '}' && top == '{') ||
                    (*it == ']' && top == '[')){
                    checkStack.pop();
                }
                else{
                    return "NO";
                }
            }

        }
    }

    if(checkStack.empty())
        return "YES";
    else   
        return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
