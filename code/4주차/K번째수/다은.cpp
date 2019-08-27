#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	int size = commands.size();

	for (int i = 0; i < size; i++) {
		vector<int> ar;
		ar = array;
		sort(ar.begin() + commands[i][0] - 1, ar.begin() + commands[i][1]);
		answer.push_back(ar[commands[i][0] + commands[i][2] - 2]);
	}

	return answer;
}