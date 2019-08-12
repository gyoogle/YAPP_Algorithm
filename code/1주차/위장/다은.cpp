#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#define INCREASE 1
using namespace std;

int solution(vector<vector<string>> clothes) {
	vector<string> clothKindVector;
	unordered_map<string, int> clothesNumHash;
	int size = clothes.size();
	int kindsize;
	int multiply = 1;
	string clothKind;
	for (int i = 0; i < size; i++) {
		clothKind = clothes[i][1];
		if (clothesNumHash.find(clothKind) != clothesNumHash.end()) {
			kindsize = clothesNumHash.find(clothKind)->second;
			clothesNumHash[clothKind] = kindsize + INCREASE;
		}
		else {
			clothesNumHash.insert(pair<string, int>(clothKind, INCREASE));
			clothKindVector.push_back(clothKind);
		}
	}
	size = clothKindVector.size();
	for (int i = 0; i < size; i++) {
		multiply *= (clothesNumHash.find(clothKindVector[i])->second + 1);
	}
	multiply = multiply - 1;
	return multiply;
}
