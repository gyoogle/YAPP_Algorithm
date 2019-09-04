class 숫자야구 {
	static char[] test = new char[3];
	static char[] check = new char[3];
	static int s, b;

	public int solution(int[][] baseball) {
		int answer = 0;

		loop: for (int t = 123; t <= 987; t++) {

			test = Integer.toString(t).toCharArray();

			for (int i = 0; i < test.length; i++) {
				if (test[i] == '0') {
					continue loop;
				}
			}

			for (int j = 0; j < test.length; j++) {
				for (int z = 0; z < test.length; z++) {
					if (j == z)
						continue;

					if (test[j] == test[z]) {
						continue loop;
					}
				}
			}

			boolean checking = true;

			for (int i = 0; i < baseball.length; i++) {

				int checkNum = baseball[i][0];
				int strike = baseball[i][1];
				int ball = baseball[i][2];

				s = b = 0;
				check = Integer.toString(checkNum).toCharArray();
				for (int j = 0; j < test.length; j++) {
					if (test[j] == check[j])
						s++;
				}
				for (int j = 0; j < test.length; j++) {
					for (int z = 0; z < test.length; z++) {
						if (j == z)
							continue;

						if (test[j] == check[z]) {
							b++;
							break;
						}
					}
				}

				if (strike != s || ball != b) {
					checking = false;
					break;
				}
			}

			if (checking)
				answer++;

		}

		return answer;
	}
}
