#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> chickenHouse;
vector<pair<int, int>> house;
int n, m,result = 99999999;
bool visited[14] = { false };
void dfs(int index, int chickenNum) {
	if (index > chickenHouse.size()) return;
	if (chickenNum == m) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int distance = 9999999;
			for (int j = 0; j < chickenHouse.size(); j++) {
				if(visited[j])
					distance = min(distance,abs(chickenHouse[j].first - house[i].first) + abs(chickenHouse[j].second - house[i].second));
			}
			sum += distance;
		}
		result = min(sum, result);
		return;
	}
	
	visited[index] = true;
	dfs(index + 1, chickenNum + 1);
	visited[index] = false;
	dfs(index + 1, chickenNum);
}
int main() {
	int num;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			if (num == 1) house.push_back(make_pair(i, j));
			if (num == 2) chickenHouse.push_back(make_pair(i, j));
		}
	}
	dfs(0, 0);
	cout << result;
}