#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    long tmp ;
    int N = h.size();
    long max = 0;
    stack<pair<int,int>> s;
    int x = 0;

    for(x = 0 ; x < N ; x ++){
        int cur = h[x];

        int prev = x;

        while(true){
            if(s.empty()){
                pair<int,int> p(cur, prev);

                s.push(p);
                break;
            }
            else{
                pair<int,int> top;

                top = s.top();

                if(top.first < cur){
                    pair<int,int> p(cur,prev);

                    s.push(p);
                    break;
                }
                else if(top.first > cur){
                    int width , height;
                    width = x - top.second ;
                    height = top.first;

                    long rec = width * height;

                    if(max < rec){
                        max = rec;
                    }

                    if(prev > top.second)
                        prev = top.second;

                    s.pop();
                }
                else{
                    break;
                }
            }
        }
    }

    while(!s.empty()){
        pair<int,int> top;

        top = s.top();

        int width , height;
        width = x - top.second ;
        height = top.first;

        long rec = width * height;

        if(max < rec){
            max = rec;
        }

        s.pop();
    }

    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
