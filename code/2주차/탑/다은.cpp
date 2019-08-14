#include <string>
#include <vector>
#include <stack>
using namespace std;
vector<int> solution(vector<int> heights) {
	int size = heights.size();
	int *a = new int[size];
	vector<int> answer(size);
	stack<pair<int, int>> numStack,storedNumStack;
	
	for (int i = 0; i < size; i++) 
		numStack.push(pair<int, int>(i, heights[i]));

	while (!numStack.empty() || !storedNumStack.empty()) {
		if (!numStack.empty()) {
			if (!storedNumStack.empty() && numStack.top().second > storedNumStack.top().second) {
				answer[storedNumStack.top().first] = numStack.top().first + 1;
				storedNumStack.pop();
			}
			else {
				storedNumStack.push(pair<int, int>(numStack.top().first, numStack.top().second));
				numStack.pop();
			}
		}
		else {
			while (storedNumStack.size() != 1) {
				numStack.push(pair<int, int>(storedNumStack.top().first, storedNumStack.top().second));
				storedNumStack.pop();
			}
			answer[storedNumStack.top().first] = 0;		
			storedNumStack.pop();
		}
	}
	return answer;
}