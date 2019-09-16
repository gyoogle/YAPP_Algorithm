#include <string>
#include <vector>
using namespace std;
vector <string> baseballnum;
int answer = 0;
void countAnswer(string num, vector<vector<int>> baseball) {
	int size = baseball.size(); int strikenum = 0, ballnum = 0; bool baseballtrue = true;
	for (int i = 0; i < size; i++) {
		string comparenum = to_string(baseball[i][0]);
		for (int j = 0; j < 3; j++) {
			if (comparenum[j] == num[j])
				strikenum++;
			else if (num.find(comparenum[j]) != string::npos)
				ballnum++;
		}
		if (baseball[i][1] != strikenum || baseball[i][2] != ballnum)
			baseballtrue = false;
		strikenum = 0; ballnum = 0;
	}
	
	if (baseballtrue) answer++;
}
void everything(string num,int placenum,bool pass[],vector<vector<int>> baseball) {
	if (placenum == 3) {
		countAnswer(num,baseball);
		return;
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (!pass[i]) {
				pass[i] = true;
				num.append(to_string(i + 1));
				everything(num, placenum + 1, pass,baseball);
				num.pop_back();
				pass[i] = false;
			}
		}
	}
}
int solution(vector<vector<int>> baseball) {
	bool pass[10] = {false,};
	string num = "";
	everything(num, 0, pass,baseball);
	return answer;
}