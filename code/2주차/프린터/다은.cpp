#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int lowPriorityNum;
	int size = priorities.size();
	queue<int> numQ;

	for (int i = 0; i < size; i++)
		numQ.push(i);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (priorities[i] < priorities[j]) {
				numQ.push(numQ.front());
				numQ.pop();
				i = numQ.front();
				j = 0;
			}
			else if (j == (size - 1)) {
				answer++;
				if (numQ.front() != location) {
					priorities[numQ.front()] = -1;
					numQ.pop();
					i = numQ.front();
					j = 0;
				}
				else
					return answer;
			}
		}
	}
}
int main(void) {
	int n,m,location,num;
	vector<int> priority;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m >> location;
		for (int j = 0; j < m; j++) {
			cin >> num;
			priority.push_back(num);
		}
		cout << solution(priority,location) << "\n";
		priority.clear();
	}
}