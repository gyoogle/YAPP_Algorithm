#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int person[][10] = { {1,2,3,4,5},{ 2, 1, 2, 3, 2, 4, 2, 5 } ,{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 } };
	int num[] = { 0,0,0 }, size = answers.size(), personSize[] = {5,8,10},max = -1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 3; j++) {
			if (answers[i] == person[j][i % personSize[j]])
				++num[j];
			if (max < num[j])
				max = num[j];
		}
	}
	for (int i = 0; i < 3; i++) {
		if (max == num[i]) 
			answer.push_back(i + 1);
	}
	return answer;
}