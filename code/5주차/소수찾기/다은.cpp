#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
string num;
vector<int> candidate;
vector<int> removeDuplicate(vector<int> candidate, string num) {
	vector<int>::iterator it;
	it = find(candidate.begin(), candidate.end(), atoi(num.c_str()));
	if (it == candidate.end() && atoi(num.c_str()) > 1) candidate.push_back(atoi(num.c_str()));
	return candidate;
}
void pick(int n,string numbers,bool check[],int pickNum) {
	if (pickNum == 0) {
		candidate = removeDuplicate(candidate,num);
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (check[i]) continue;
			check[i] = true;
			num.push_back(numbers[i]);
			pick(n, numbers, check, pickNum - 1);
			check[i] = false;
			num.pop_back();
		}
	}
}
int returnPrimeNum() {
	int answer = 0;
	int size = candidate.size();
	bool primeNumTrue = true;
	for (int i = 0; i < size; i++) {
		for (int j = 2; j <= sqrt(candidate[i]); j++) {
			if ((candidate[i] % j) == 0) { primeNumTrue = false; break; }
		}
		if (primeNumTrue) answer++;
		primeNumTrue = true;
	}
	return answer;
}
int solution(string numbers) {
	int size = numbers.size();
	bool *check = new bool[size];
	for(int i = 1; i <= size; i++)
		pick(10, numbers,check, i);
	return returnPrimeNum();
}