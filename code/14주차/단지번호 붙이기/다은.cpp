#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int directx[] = { 1,-1,0,0 };
int directy[] = { 0,0,1,-1 };
vector<int> homeNumberVector;
int n,visited[25][25],num = 1;
string house[25];
void initVisited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
}
void initHouse() {
	for (int i = 0; i < n; i++)
		cin >> house[i];
}
void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int dx = directx[i] + x;
		int dy = directy[i] + y;
		if (dx >= 0 && dy >= 0 && dx < n && dy < n && !visited[dx][dy] && house[dx][dy] == '1') {
			num++;
			dfs(dx, dy);
		}
	}
}
void searchDfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (house[i][j] == '1' && !visited[i][j]) {
				dfs(i, j);
				homeNumberVector.push_back(num);
				num = 1;
			}
		}
	}
}
int main(void) {
	cin >> n;
	initHouse();
	initVisited();
	searchDfs();
	sort(homeNumberVector.begin(), homeNumberVector.end());
	cout << homeNumberVector.size() << "\n";
	for (int i : homeNumberVector)
		cout << i << "\n";
}