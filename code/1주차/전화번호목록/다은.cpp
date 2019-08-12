#include <string>
#include <vector>
#include <unordered_map>
#include<iostream>
#define KEYINDEX 5
using namespace std;
bool solution(vector<string> phone_book) {
	bool answer = true;
	int size = phone_book.size();
	int phoneLength, hashSize, count = -1;
	vector<string> shortNumberVector;
	string newKey, newValue, storedValue;
	unordered_map<string, string> numberhash;

	for (int i = 0; i < size; ++i) {
		phoneLength = phone_book[i].length();
		hashSize = numberhash.size();
		if (phoneLength >= KEYINDEX) {
			newKey = phone_book[i].substr(0, KEYINDEX);
			newValue = phone_book[i].substr(KEYINDEX);
			if (hashSize > 0 && numberhash.find(newKey) != numberhash.end()) {
				storedValue = numberhash.find(newKey)->second;
				if (newValue.find(storedValue) == 0 || storedValue.find(newValue) == 0) {
					answer = false;
					break;
				}
				else {
					shortNumberVector.push_back(phone_book[i]);
				}
			}
			else {
				numberhash.insert(pair<string, string>(newKey, newValue));
			}
		}
		else if (hashSize > 0) {
			for (unordered_map<string, string>::iterator iter = numberhash.begin(); iter != numberhash.end(); ++iter) {
				if (iter->first.find(phone_book[i]) == 0) {
					answer = false;
					break;
				}
			}
			if (answer == true)
				shortNumberVector.push_back(phone_book[i]);
			else break;
		}
		else
			shortNumberVector.push_back(phone_book[i]);
	}
	if (answer == true) {
		size = shortNumberVector.size();
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (i != j && shortNumberVector[i].find(shortNumberVector[j]) == 0)
					answer = false;
			}
			if (answer == false) break;
		}
	}
	return answer;
}