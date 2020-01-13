#include<stdio.h>
#define DIV 9901
#define MAX 100000

int main(void) {

	int dp[3][MAX + 1] = { 0 };
	int num, i, total;

	scanf("%d", &num);


	dp[0][1] = 1;
	dp[1][1] = 1;
	dp[2][1] = 1;
	for (i = 2; i <= num; i++) {
		dp[0][i] = (dp[1][i - 1] + dp[2][i - 1]) % DIV;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % DIV;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % DIV;
	}
	total = (dp[0][num] + dp[1][num] + dp[2][num]) % DIV;

	printf("%d\n", total);
	return 0;
}