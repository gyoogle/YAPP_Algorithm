#include <string>
#include <vector>
using namespace std;

int solution(string arrangement) {
	int answer = 0;
	int charCount = 0;
	int size = arrangement.size();

	for (int i = 0; i < size; i++) {
		if (arrangement[i] == '(' && arrangement[i + 1] == '(') 
			charCount++;
		else if(arrangement[i] == '(' && arrangement[i + 1] == ')') {
			answer += charCount;
			i++;
		}
		else if (arrangement[i] == ')') {
			charCount--;
			answer += 1;
		}
	}
	return answer;
}