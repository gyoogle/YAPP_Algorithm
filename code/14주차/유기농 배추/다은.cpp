#include<iostream>
#include<string.h>
using namespace std;
int cabbage[50][50];
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
int visited[50][50];
int m, n, k,num = 0;
void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int dx = directx[i] + x;
		int dy = directy[i] + y;
		if (dx >= 0 && dy >= 0 && dx < m && dy < n && !visited[dx][dy] && cabbage[dx][dy]) 
			dfs(dx, dy);
	}
}
void searchDfs() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && cabbage[i][j]) {
				dfs(i, j);
				num++;
			}
		}
	}
}
int main(void) {
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		memset(cabbage, 0, sizeof(cabbage));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			cabbage[x][y] = 1;
		}
		searchDfs();
		cout << num << "\n";
		num = 0;
	}
}