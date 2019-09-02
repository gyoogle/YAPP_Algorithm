#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0; int size = citations.size(); int j;
	sort(citations.begin(), citations.end());
	for (int i = 0; i < citations[size - 1]; i++) {
		for (j = 0; j < size; j++) {
			if (i <= citations[j] && (size - j) >= i) {
				answer = i;
				break;
			}
			else if (i <= citations[j] && (size - j) < i)
				return answer;
		}
	}
}