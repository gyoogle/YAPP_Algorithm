#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);
double getMedian(int trdatas[],int d){
    int count = 0;
    double median;
    
    if(d % 2 != 0){
        for(int i = 0; i <= 200; i++){
            count += trdatas[i];
            if(count > d / 2){
                median = i;
                break;
            }
        }
    }
    else{
        int firstData = 0,secondData = 0;
        for(int i = 0; i <= 200; i++){
            count += trdatas[i];
            if(firstData == 0 && count >= d / 2)
                firstData = i;
            if(secondData == 0 && count >= d / 2 + 1){
                secondData = i;
                break;
            }
        }
        median = (firstData + secondData) / 2.0;
    }
    
    return median;
}

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int trdatas[201] = {0},answer = 0;
    for(int i = 0; i < d; i++)
        trdatas[expenditure[i]]++;
    for(int i = d; i < expenditure.size(); i++){
        double median = getMedian(trdatas,d);
        cout << median << "\n";
        if(median *2 <= expenditure[i])
            answer++;
        trdatas[expenditure[i - d]]--;
        trdatas[expenditure[i]]++;
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
