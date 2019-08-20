#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int num = 0;
	priority_queue<int,vector<int>,greater<int>> priorityQ;
	int size = scoville.size();

	for (int i = 0; i < size; i++)
		priorityQ.push(scoville[i]);

	while (priorityQ.top() < K) {
		num = priorityQ.top();
		priorityQ.pop();
		if (priorityQ.empty()) return -1;
		priorityQ.push(num + priorityQ.top() * 2);
		priorityQ.pop();
		answer++;
	}
	return answer;
}