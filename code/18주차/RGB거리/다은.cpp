#include <iostream>
#include <vector>
#include <algorithm>
#define COLORSIZE 3
using namespace std;

int main(void) {
	vector<vector<int>> color;

	int colorNum;
	cin >> colorNum;
	for (int i = 0; i < colorNum; i++) {
		vector <int> house;
		for (int j = 0; j < COLORSIZE; j++) {
			int colorValue;
			cin >> colorValue;
			house.push_back(colorValue);
		}
		color.push_back(house);
	}
	for (int i = 0; i < colorNum - 1; i++) {
		color[i + 1][0] += min(color[i][1], color[i][2]);
		color[i + 1][1] += min(color[i][0], color[i][2]);
		color[i + 1][2] += min(color[i][0], color[i][1]);
	}

	int result = min(color[colorNum - 1][0], color[colorNum - 1][1]);
	result = min(result, color[colorNum - 1][2]);
	cout << result;
}