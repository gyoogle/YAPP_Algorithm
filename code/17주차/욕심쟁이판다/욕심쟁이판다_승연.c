#include<stdio.h>

int num, i, j;
int panda[500][500];
int visited[500][500];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,-1,1,0 };

int Max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int dp(int a, int b) {
	int k;
	for (k = 0; k < 4; k++) {
		if (a + dx[k] >= 0 && a + dx[k] < num && b + dy[k] >= 0 && b + dy[k] < num) {
			if (panda[a][b] < panda[a + dx[k]][b + dy[k]]) {//대나무 확인
				if (visited[a + dx[k]][b + dy[k]] == 1) {
					visited[a][b] = Max(visited[a][b], dp(a + dx[k], b + dy[k]) + 1);
				}
				else {
					visited[a][b] = Max(visited[a][b], visited[a + dx[k]][b + dy[k]] + 1);
				}
			}
		}
	}
	return visited[a][b];
}
int main(void) {
	int max = 1;
	for (i = 0; i < 500; i++) {
		for (j = 0; j < 500; j++) {
			visited[i][j] = 1;
		}
	}
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			scanf("%d", &panda[i][j]);
		}
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			max = Max(max, dp(i, j));
		}
	}
	printf("%d\n", max);
	return 0;
}

