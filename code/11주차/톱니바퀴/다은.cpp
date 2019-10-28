#include <iostream>
#include <string>
using namespace std;
string gear[4];
int score[] = { 1,2,4,8 };
void rotate(int index,int rotateState) {
	if (rotateState == -1) {
		int temp = gear[index][0];
		for (int i = 1; i < 8; i++)
			gear[index][i - 1] = gear[index][i];
		gear[index][7] = temp;
	}
	else {
		int temp = gear[index][7];
		for (int i = 6; i >= 0; i--)
			gear[index][i + 1] = gear[index][i];
		gear[index][0] = temp;
	}
}
void initGear() {
	for (int i = 0; i < 4; i++)
		cin >> gear[i];
}
void rotateGear(int n) {
	for (int i = 0; i < n; i++) {
		int num, rotatestate;
		char number,number2;
		cin >> num >> rotatestate;
			if (num == 1) {
				number = gear[0][2];
				rotate(0,rotatestate);
				if (number != gear[1][6]) {
					number = gear[1][2];
					rotate(1, rotatestate*-1);
					if (number != gear[2][6]) {
						number = gear[2][2];
						rotate(2, rotatestate);
						if (number != gear[3][6])
							rotate(3, rotatestate*-1);
					}
				}
			}
			else if (num == 2) {
				number = gear[1][6];
				number2 = gear[1][2];
				rotate(1, rotatestate);
				if (gear[0][2] != number) 
					rotate(0, rotatestate*-1);
			
				if (number2 != gear[2][6]) {
					number = gear[2][2];
					rotate(2, rotatestate*-1);
					if (number != gear[3][6])
						rotate(3,rotatestate);
				}
			}
			else if (num == 3) {
				number = gear[2][6];
				number2 = gear[2][2];
				rotate(2,rotatestate);
				if (number != gear[1][2]) {
					number = gear[1][6];
					rotate(1, rotatestate*-1);
					if (number != gear[0][2])
						rotate(0,rotatestate);
				}
				if (number2 != gear[3][6])
					rotate(3, rotatestate*-1);
			}
			else {
				number = gear[3][6];
				rotate(3,rotatestate);
				if (number != gear[2][2]) {
					number = gear[2][6];
					rotate(2, rotatestate*-1);
					if (number != gear[1][2]) {
						number = gear[1][6];
						rotate(1,rotatestate);
						if (number != gear[0][2]) {
							rotate(0, rotatestate*-1);
						}
					}
				}
			}
		}
}
int getscore() {
	int sum = 0;
	for (int i = 0; i < 4; i++) 
		sum += (gear[i][0] - '0')*score[i];
	return sum;
}
 int main(void) {
	initGear();
	int n;
	cin >> n;
	rotateGear(n);
	cout << getscore();
}