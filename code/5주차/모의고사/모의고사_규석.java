class 모의고사 {
	static int[] one = { 1, 2, 3, 4, 5 };
	static int[] two = { 2, 1, 2, 3, 2, 4, 2, 5 };
	static int[] three = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	static int on, tw, th;

	public static int[] solution(int[] answers) {
		int[] answer = {};
		int idx1 = 0;
		int idx2 = 0;
		int idx3 = 0;
		on = tw = th = 0;
		for (int i = 0; i < answers.length; i++) {

			if (answers[i] == one[idx1++]) {
				on++;
			}
			if (answers[i] == two[idx2++]) {
				tw++;
			}
			if (answers[i] == three[idx3++]) {
				th++;
			}

			if (idx1 == one.length)
				idx1 = 0;
			if (idx2 == two.length)
				idx2 = 0;
			if (idx3 == three.length)
				idx3 = 0;
		}

		int max = Math.max(Math.max(on, tw), th);
		int[] temp = new int[3];
		int index = 0;
		if (on == max) {
			temp[index++] = 1;
		}
		if (tw == max) {
			temp[index++] = 2;
		}
		if (th == max) {
			temp[index++] = 3;
		}

		answer = new int[index];

		index = 0;
		for (int i = 0; i < temp.length; i++) {
			if (temp[i] != 0) {
				answer[index++] = temp[i];
			}
		}

		return answer;
	}

}
