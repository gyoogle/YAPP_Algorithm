#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n,k,toyPrice,answer = 0;
    cin >> n >> k;
    vector<int> toyVector;
    for(int i = 0; i < n; i++){
        cin >> toyPrice;
        toyVector.push_back(toyPrice);
    }
    sort(toyVector.begin(),toyVector.end());
    for(int toy : toyVector){
        if(k >= toy){
            k -= toy;
            answer++;
        }
        else break;
    }
    cout << answer;
}