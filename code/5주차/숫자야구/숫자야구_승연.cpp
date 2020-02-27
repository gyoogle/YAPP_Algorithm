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
			//k,p�� ��������
			for (int k = 0; k<3; k++) {
				for (int p = 0; p<3; p++) {
					tmp = to_string(baseball[j][0]);
					if (k == p&&num[k] == tmp[p]) {
						strike++;
						continue;
					}//��ġ�� ���� ���빰�� ������ ��Ʈ����ũ
					if (k != p&&num[k] == tmp[p]) {
						ball++;
						continue;
					}//��ġ�� �ٸ��� ���빰�� ������
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