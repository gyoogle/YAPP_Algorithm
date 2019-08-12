#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#define ONE_PERSON 0
#define DUPLICATE -1
#define DECREASE 1
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	int size;
	unordered_map<string, int> completionHash;

	size = completion.size();
	for (int i = 0; i < size; ++i) {
		int hashsize = completionHash.size();
		if (hashsize != 0 && completionHash.find(completion[i]) != completionHash.end()) {
			int count = completionHash.find(completion[i])->second;
			if (count <= ONE_PERSON) {
				completionHash.erase(completion[i]);
				completionHash.insert(pair<string, int>(completion[i], count + DUPLICATE));
			}
		}
		else {
			completionHash.insert(pair<string, int>(completion[i], ONE_PERSON));
		}
	}
	size = size + 1;
	for (int i = 0; i < size; ++i) {
		if (completionHash.find(participant[i]) == completionHash.end()) {
			answer = participant[i];
			break;
		}
		else {
			int count = completionHash.find(participant[i])->second;
			if (count != ONE_PERSON) {
				completionHash.erase(participant[i]);
				completionHash.insert(pair<string, int>(participant[i], count + DECREASE));
			}
			else if (count == ONE_PERSON) {
				completionHash.erase(participant[i]);
			}
		}
	}
	return answer;
}