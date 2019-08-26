
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0, j = 0, i = 0;
	priority_queue<int> supplyQ;

	while (1) {
		if (dates[j] == i) {
			supplyQ.push(supplies[j]);
			j++;
		}
		if (stock == 0) {
			stock += supplyQ.top();
			supplyQ.pop();
			answer++;
			if ((k - i) <= stock) return answer;
		}
		stock--;
		i++;
	}
}