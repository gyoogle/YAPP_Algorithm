#include<stdio.h>
#include<stdlib.h>
#define DIV 1000000009
int t, n;
int i;
long long dp[1000001];

int main() {
	scanf("%d", &t);
	int j;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (j = 4; j < 1000001; j++) {
		dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % DIV;
		dp[j] %= DIV;
	}
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}

	return 0;
}



