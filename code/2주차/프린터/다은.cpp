#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int highPriorityNum;
	int size = priorities.size();
	queue<pair<int,int>> numQ;
	priority_queue<int> priorityQ;

	for (int i = 0; i < size; i++) {
		numQ.push({ i, priorities[i] });
		priorityQ.push(priorities[i]);
	}

	while (!priorityQ.empty()) {
		highPriorityNum = priorityQ.top();
		if (highPriorityNum > numQ.front().second) {
			numQ.push(pair<int,int>(numQ.front().first, numQ.front().second));
			numQ.pop();
		}
		else {
			if (numQ.front().first == location)
				return (answer + 1);
			priorityQ.pop();
			numQ.pop();
			answer++;
		}
	}
}