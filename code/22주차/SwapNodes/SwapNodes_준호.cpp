#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>

using namespace std;

/*
 * Complete the swapNodes function below.
 */

void swapNode(vector<vector<int>>& indexes , int row, int level, int query){
    if(level % query == 0){
        int swap = indexes[row][1];
        indexes[row][1] = indexes[row][0];
        indexes[row][0] = swap;
    }

    for(int column = 0 ; column < 2 ; column ++){
        if(indexes[row][column] != -1){
            swapNode(indexes, indexes[row][column] - 1, level + 1, query);
        }
    }
}

//복사하는데에도 시간이 소모가 되기 때문에 argument를 반드시 참조연산자를 이용해야한다
void inOrderSearch(vector<int>& res, vector<vector<int>>& indexes, int node){
    
    int left = indexes[node][0] ;
    int right = indexes[node][1];

    if(left == -1){
        res.push_back(node + 1);
    }
    else{
        inOrderSearch(res, indexes, left - 1);
        res.push_back(node + 1);
    }

    if(right != -1)
        inOrderSearch(res, indexes, right -1);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
     * Write your code here.
     */
    
    vector<vector<int>> res(queries.size());

    for(int i = 0 ; i < queries.size() ; i ++){
        swapNode(indexes, 0, 1, queries[i]);
        inOrderSearch(res[i], indexes, 0);
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
