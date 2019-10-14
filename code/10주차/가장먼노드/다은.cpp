#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> *adj;
int *depth,num,maxnum = 0;
void initAdj(vector<vector<int>> &edge) {
	adj = new vector<int>[num];
	for (int i = 0; i < edge.size(); i++) {
		adj[edge[i][0] - 1].push_back(edge[i][1] - 1);
		adj[edge[i][1] - 1].push_back(edge[i][0] - 1);
	}
}
void initDepth() {
	depth = new int[num];
	for (int i = 0; i < num; i++) {
		depth[i] = 0;
	}
}
void bfs() {
	queue <int> q;
	q.push(0);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < adj[x].size(); i++) {
			if (!depth[adj[x][i]]) {
				q.push(adj[x][i]);
				depth[adj[x][i]] = depth[x] + 1;
				if (maxnum < depth[adj[x][i]]) maxnum = depth[adj[x][i]];
			}
		}
	}
}
int countAnswer() {
	int answer = 0;
	for (int i = 0; i < num; i++) {
		if (depth[i] == maxnum)
			answer++;
	}
	return answer;
}
int solution(int n, vector<vector<int>> edge) {
	num = n;
	initDepth();
	initAdj(edge);
	bfs();
	return countAnswer();
}