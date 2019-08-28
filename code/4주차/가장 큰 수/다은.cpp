#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool sorting(string &a, string &b) {
	string num1, num2; 
	num1.append(a); num1.append(b); num2.append(b); num2.append(a);
	
	if (num1 > num2)
		return true;

	return false;
}

string solution(vector<int> numbers) {
	string answer = ""; vector<string> placeValue; int size = numbers.size();

		for (int i = 0; i < size; i++) 
			placeValue.push_back(to_string(numbers[i]));
		
		if(size > 0)
			sort(placeValue.begin(), placeValue.end(), sorting);

		for (int i = 0; i < size; i++)
			answer.append(placeValue[i]);

	if (answer[0] == '0') return "0";

	return answer;
}