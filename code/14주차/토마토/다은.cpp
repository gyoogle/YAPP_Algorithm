#include <iostream>
#include<string.h>
#include <queue>
using namespace std;
int directx[] = { 0,0,1,-1 };
int directy[] = { 1,-1,0,0 };
int depth[1000][1000];
int tomato[1000][1000], m, n,maxnum = 0;
queue<pair<int, int>> q;
void initTomato() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) 
				q.push(make_pair(i, j));
		}
	}
}
void bfs() {
	pair<int, int> node;
	while (!q.empty()){
		node = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = directx[i] + node.first;
			int dy = directy[i] + node.second;
			if (dx >= 0 && dy >= 0 && dx < m && dy < n && !depth[dx][dy] && tomato[dx][dy] == 0) {
				tomato[dx][dy] = 2;
				depth[dx][dy] += depth[node.first][node.second] + 1;
				q.push(make_pair(dx, dy));
				if (maxnum < depth[dx][dy]) maxnum = depth[dx][dy];
			}
		}
	}
}
int main(void) {
	cin >> n >> m;
	memset(depth, 0, sizeof(depth));
	initTomato();
	bfs();
	bool ripeTrue = true;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (tomato[i][j] == 0) {
				ripeTrue = false;
				break;
			}
		}
		if (!ripeTrue) break;
	}
	if (ripeTrue)
		cout << maxnum;
	else
		cout << -1;
}