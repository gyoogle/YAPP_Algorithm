#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int wantstick;
	cin >> wantstick;
	if (wantstick == 64) { cout << 1; return 0; }
	vector<int> stick;
	stick.push_back(64);
	while (1) {
		int sum = 0;
		int num = stick[stick.size() - 1] / 2;
		stick.pop_back();
		for (int i = 0; i < stick.size(); i++)
			sum += stick[i];
		if (sum + num > wantstick) stick.push_back(num);
		else if (sum + num == wantstick) {
			cout << stick.size() + 1;
			break;
		}
		else {
			stick.push_back(num);
			stick.push_back(num);
		}
	}
}