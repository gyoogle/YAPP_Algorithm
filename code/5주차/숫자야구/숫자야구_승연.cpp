#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
	bool flag = true;
	string num = "";
	string tmp = "";
	int strike = 0;
	int ball = 0;
	int answer = 0;
	for (int i = 123; i<987; i++) {
		num = to_string(i);
		if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2]) continue;
		if (num[0] == '0' || num[1] == '0' || num[2] == '0') continue;
		for (int j = 0; j<baseball.size(); j++) {
			strike = 0;
			ball = 0;
			flag = true;
			//k,p는 위주추적
			for (int k = 0; k<3; k++) {
				for (int p = 0; p<3; p++) {
					tmp = to_string(baseball[j][0]);
					if (k == p&&num[k] == tmp[p]) {
						strike++;
						continue;
					}//위치가 같고 내용물도 같으면 스트라이크
					if (k != p&&num[k] == tmp[p]) {
						ball++;
						continue;
					}//위치가 다르고 내용물이 같으면
				}
			}
			if (baseball[j][1] != strike || baseball[j][2] != ball) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			answer++;
		}
	}
	return answer;
}