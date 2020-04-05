#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    vector<int> sum;
    int maxNum = arr[0], answer = arr[0];
    if(arr.size() <= 2) return 0;
    for(int i = 0; i < arr.size(); i++){
        if(i - 2 < 0){
            sum.push_back(arr[i]);
            if(answer < sum[i]) answer = sum[i];
        }
        else{
            maxNum = max(maxNum, sum[i - 2]);
            int num = max(max(maxNum + arr[i], maxNum), arr[i]);
            if(answer < num) answer = num;
            sum.push_back(num);
        }
    }
    return answer;
}