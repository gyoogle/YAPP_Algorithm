class 소수찾기 {
	public static int[] arr;
	public static int[] set;
	public static boolean[] visited;
	public static int cnt;
	public static boolean[] confirm;

	public static int solution(String numbers) {
		int answer = 0;

		String[] s = numbers.split("");
		arr = new int[s.length];
		for (int i = 0; i < s.length; i++) {
			arr[i] = Integer.parseInt(s[i]);
		}

		visited = new boolean[arr.length];
		confirm = new boolean[10000000];
		cnt = 0;
		for (int i = 1; i <= s.length; i++) {
			set = new int[i];
			perm(0, i);
		}

		answer = cnt;

		return answer;
	}

	public static void perm(int len, int r) {

		if (len == r) {
			String temp = "";
			for (int i = 0; i < set.length; i++) {
				temp += Integer.toString(set[i]);
			}
			if (check(temp)) {
				if (!confirm[Integer.parseInt(temp)]) {
					confirm[Integer.parseInt(temp)] = true;
					cnt++;
				}
			}
			return;
		}

		for (int i = 0; i < arr.length; i++) {
			if (!visited[i]) {
				set[len] = arr[i];
				visited[i] = true;
				perm(len + 1, r);
				visited[i] = false;
			}
		}

	}

	// 소수 판별
	public static boolean check(String temp) {
		int num = Integer.parseInt(temp);
		if (num == 1 || num == 0)
			return false;
		for (int i = 2; i < num; i++) {
			if (num % i == 0)
				return false;
		}

		return true;
	}
}
