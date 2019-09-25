#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	int node;
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			answer++;
			q.push(i);
			node = q.front();
			visited[i] = true;
			while (!q.empty()) {
				q.pop();
				for (int j = 0; j < n; j++) {
					if (computers[node][j] == 1 && visited[j] == false) {
						q.push(j);
						visited[j] = true;
					}
				}
				node = q.front();
			}
		}
	}
	return answer;
}