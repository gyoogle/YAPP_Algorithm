#include <cstdio>
#include <algorithm>

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int n, k, cnt[26 * 26];
char array[26][26];

void dfs(int x, int y) {
	array[x][y] = '0', cnt[k]++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (array[nx][ny] == '1') dfs(nx, ny);
	}
}

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%s", array[i] + 1);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (array[i][j] == '1')
				dfs(i, j), k++;

		}
	}
	std::sort(cnt, cnt + k);

	printf("%d\n", k);
	for (i = 0; i < k; i++) printf("%d\n", cnt[i]);

	return 0;
}