#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> budgets, int M) {
	sort(budgets.begin(), budgets.end());
	int size = budgets.size();
	int left = 0, right = budgets[size - 1], mid, sum = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		for (int i = 0; i < size; i++) {
			if (budgets[i] > mid)
				sum += mid;
			else
				sum += budgets[i];
		}
		if (M > sum) left = mid + 1;
		else right = mid - 1;
		sum = 0;
	}
	return right;
}