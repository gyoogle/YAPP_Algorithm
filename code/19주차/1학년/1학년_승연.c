#include<stdio.h>

int main() {
	int n, i, j;
	long long dp[101][21] = { 0 };
	int arr[101];

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[1][arr[1]] = 1;
	int m, k;
	for (i = 1; i <= n - 1; i++) {
		for (j = 0; j <= 20; j++) {
			if (dp[i][j] > 0) {
				k = j + arr[i + 1];
				m = j - arr[i + 1];
				if (k >= 0 && k <= 20) {
					dp[i + 1][k] += dp[i][j];
				}
				if (m >= 0 && m <= 20) {
					dp[i + 1][m] += dp[i][j];
				}
			}
		}
	}
	printf("%lld\n", dp[n - 1][arr[n]]);
	return 0;

}
