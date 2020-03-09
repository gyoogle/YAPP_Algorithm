#include <iostream>
#include <unordered_map>
using namespace std;

int main(void)
{
    int t, money, arrSize;
    cin >> t;
    for (int i = 0; i < t; i++){
        unordered_map<int, int> icecream;
        cin >> money >> arrSize;
        for (int j = 0; j < arrSize; j++){
            int cost;
            cin >> cost;
            if(cost >= money) continue;
            if (icecream.find(cost) == icecream.end())
            {
                icecream.insert(make_pair(cost, j + 1));
                if (icecream.find(money - cost) != icecream.end() && icecream.find(money - cost) != icecream.find(cost))
                    cout << icecream[money - cost] << " " << icecream[cost] << "\n";
            }
            else if (money - cost == cost){
                cout << icecream[cost] << " " << j + 1 << "\n";
            }
        }
    }
}