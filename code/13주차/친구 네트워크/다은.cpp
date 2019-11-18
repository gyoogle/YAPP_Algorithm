#include <iostream>
#include<string>
#include <map>
using namespace std;
int root[200001];
int member[200001] = {1,};
int find(int num) {
	if (root[num] == num)
		return num;
	else
		return find(root[num]);
}
int unionMap(int f1num,int f2num) {
	f1num = find(f1num);
	f2num = find(f2num);

	if (f1num != f2num) {
		root[f2num] = root[f1num];
		member[f1num] += member[f2num];
		member[f2num] = 1;
	}
	return member[f1num];
}
int main(void) {
	int t;
	cin >> t;
	while (1) {
		if (t == 0) break;
		int n,index = 1;
		cin >> n;
		for (int i = 1; i <= n * 2; i++) {
			root[i] = i;
			member[i] = 1;
		}
		map<string, int> friendMap;
		for (int i = 0; i < n; i++) {
			string f1, f2;
			cin >> f1 >> f2;
			if (friendMap.count(f1) == 0)
				friendMap[f1] = index++;
			if (friendMap.count(f2) == 0)
				friendMap[f2] = index++;
			cout << unionMap(friendMap[f1], friendMap[f2]) << "\n";
		}
		t--;
	}
}