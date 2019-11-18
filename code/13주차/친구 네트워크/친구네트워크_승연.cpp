#include <stdio.h>
#include <string>
#include <map>
using namespace std;

int vertex[200001], gc[200001];
int c;
char a[22], b[22];

int find(int x) {
	return x == vertex[x] ? x : vertex[x] = find(vertex[x]);
}

int Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		vertex[y] = x;
		gc[x] += gc[y];
		gc[y] = 1;
	}
	return gc[x];
}

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		int F, cnt = 0;
		map<string, int> map;
		scanf("%d", &F);
		for (int i = 0; i < 2 * F; i++) vertex[i] = i, gc[i] = 1;
		while (F--) {
			scanf(" %s %s", &a, &b);
			if (!map.count(a)) map[a] = cnt++;
			if (!map.count(b)) map[b] = cnt++;
			printf("%d\n", Union(map[a], map[b]));
		}
	}
	return 0;
}
