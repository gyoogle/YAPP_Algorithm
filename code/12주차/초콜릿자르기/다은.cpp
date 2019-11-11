#include <iostream>

using namespace std;

int main(void) {
	int n, m;
	int chocolate[302][302];
	cin >> n >> m;
	chocolate[1][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			chocolate[i+1][j] = chocolate[i][j] + j;
			chocolate[i][j + 1] = chocolate[i][j] + i;
		}
	}
	cout << chocolate[n][m];
}