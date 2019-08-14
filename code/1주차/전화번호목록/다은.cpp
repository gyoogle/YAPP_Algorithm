#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
bool solution(vector<string> phone_book) {
	int size = phone_book.size();
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < size; i++) {
		if (i != size - 1 && phone_book[i + 1].find(phone_book[i]) == 0) {
			answer = false;
			break;
		}
	}
	return answer;
}