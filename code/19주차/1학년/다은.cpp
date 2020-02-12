#include <iostream>
#include <vector>
using namespace std;
int equalNum;
long long memo[200][200];
void initMemo() {
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 100; j++) {
			memo[i][j] = -1;
		}
	}
}
long long dfs(int sum,int index,int max,vector<int> &numVector) {
	if (sum < 0 || sum > 20) return 0;
	if (index == max) {
		if (sum == equalNum)
			memo[sum][index] = 1;
		else
			memo[sum][index] = 0;
		return memo[sum][index];
	}
	if (memo[sum][index] != -1) return memo[sum][index];
	memo[sum][index] = dfs(sum + numVector[index], index + 1, max, numVector)
+ dfs(sum - numVector[index], index + 1, max, numVector);
	return memo[sum][index];
	
}
int main(void) {
	int num;
	cin >> num;
	vector<int> numVector;
	for (int i = 0; i < num; i++) {
		int number;
		cin >> number;
		numVector.push_back(number);
	}
	equalNum = numVector[numVector.size() - 1];
	initMemo();
	cout << dfs(numVector[0], 1, numVector.size() - 1, numVector);
}