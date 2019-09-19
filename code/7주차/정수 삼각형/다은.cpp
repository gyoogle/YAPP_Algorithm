#include <vector>
#include<algorithm>
#include<functional>
using namespace std;

int solution(vector<vector<int>> triangle) {
	for (int i = 1; i < triangle.size(); i++) {
		int size = triangle[i].size();
		for (int j = 0; j < size; j++) {
			if (j == 0) triangle[i][j] += triangle[i - 1][j];
			else if (j == size - 1) triangle[i][j] += triangle[i - 1][j - 1];
			else {
				triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
			}
		}
	}
	return *max_element(triangle[triangle.size()-1].begin(), triangle[triangle.size() - 1].end());
}