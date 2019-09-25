#include <vector>
using namespace std;
int numsize, answer = 0, targetNum; vector<int>number;
void makeNumber(int sum, int index) {
	if (index == numsize) {
		if (targetNum == sum) answer++;
		return;
	}
	else {
		number[index] *= 1;
		makeNumber(sum + number[index], index + 1);
		number[index] *= -1;
		makeNumber(sum + number[index], index + 1);
	}
}
int solution(vector<int> numbers, int target) {
	numsize = numbers.size(); targetNum = target; number = numbers;
	makeNumber(0, 0);
	return answer;
}