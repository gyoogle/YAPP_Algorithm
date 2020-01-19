#include<stdio.h>
int Min(int a, int b) {
	return a > b ? b : a;
}
int main() {
	int n, i, j;
	scanf("%d", &n);
	int rgb[1000][3] = { 0 };
	int dist[1001][3];
	dist[0][0] = dist[0][1] = dist[0][2] = 0;

	for (i = 1; i <= n; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &rgb[i][j]);
		}
	}

	for (i = 1; i <= n; i++) {
		dist[i][0] = Min(dist[i - 1][1], dist[i - 1][2]) + rgb[i][0];
		dist[i][1] = Min(dist[i - 1][0], dist[i - 1][2]) + rgb[i][1];
		dist[i][2] = Min(dist[i - 1][0], dist[i - 1][1]) + rgb[i][2];
	}
	printf("%d\n", Min(Min(dist[n][0], dist[n][1]), dist[n][2]));
	return 0;

}
