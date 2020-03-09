#include <bits/stdc++.h>
#include <algorithm>
#include <utility>

using namespace std;

vector<string> split_string(string);

int compare (const void * a, const void * b)
{
    if( ((pair<int,int> *)a) -> second == ((pair<int,int> *)b) -> second){
        return ((pair<int,int> *)a) -> first - ((pair<int,int> *)b) -> first;
    }
    else{
        return ((pair<int,int> *)a) -> second - ((pair<int,int> *)b) -> second;
    }
}

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {

    vector<pair<int,int>> item(cost.size());
    for(int i = 0 ; i < cost.size() ; i ++){
        item[i] = make_pair(i + 1, cost[i]);
    }
    qsort(&item[0], item.size(), sizeof(item[0]), compare);
    

    for(int i = 0 ; i < cost.size() -1 ; i ++){

        int mid ;
        int start = i + 1;
        int end = cost.size();

        while(start <= end){
            mid = (end + start) / 2;

            if(item[i].second + item[mid].second == money){
                if(item[i].first < item[mid].first){
                    cout << item[i].first << " " << item[mid].first << "\n";
                }
                else{
                    cout << item[mid].first << " " << item[i].first << "\n";
                }
                
                break;
            }
            else if(item[i].second + item[mid].second > money){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        if(item[i].second + item[mid].second == money){
            break;
        }
    }



}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
