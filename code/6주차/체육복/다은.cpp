#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void lendingUniform(vector<int> &lost, vector<int> &reserve, int num) {
	int lostsize = lost.size();
	for (int i = 0; i < lostsize;) {
		vector<int>::iterator it = find(reserve.begin(), reserve.end(), lost[i] - num);
		if (it != reserve.end()) {
			reserve.erase(it);
			lost.erase(lost.begin() + i);
		}
		else i++;
	}
}
int solution(int n, vector<int> lost, vector<int> reserve) {
	lendingUniform(lost, reserve, 0);
	lendingUniform(lost, reserve, -1);
	lendingUniform(lost, reserve, 1);

	return n - lost.size();
}