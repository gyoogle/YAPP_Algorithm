#include <vector>
using namespace std;

long long solution(int N) {
	vector<long long> tile;  tile.push_back(1); tile.push_back(1);

	for (int i = 0; i < N - 1; i++) 
		tile.push_back(tile[i] + tile[i + 1]);
	
	if (N == 1) return tile[N - 1] * 4;
	else if (N == 2) return tile[N - 1] * 3 + tile[N - 2] * 3;
	else if (N == 3) return tile[N - 1] * 3 + tile[N - 2] * 2 + tile[N - 3] * 2;
	else return tile[N - 1] * 3 + tile[N - 2] * 2 + tile[N - 3] * 2 + tile[N - 4]; 
	
}