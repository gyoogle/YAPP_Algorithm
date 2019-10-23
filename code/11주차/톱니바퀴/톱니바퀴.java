import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 톱니바퀴 {

	static int K; // 자석 회전시키는 횟수
	static int[] J1;
	static int[] J2;
	static int[] J3;
	static int[] J4;
	static int score;

	static int N;
	static int rotate;
	static boolean chk1;
	static boolean chk2;
	static boolean chk3;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		J1 = new int[8];
		J2 = new int[8];
		J3 = new int[8];
		J4 = new int[8];

		String[] str = br.readLine().split("");

		// 자석 입력
		for (int j = 0; j < 8; j++) {
			J1[j] = Integer.parseInt(str[j]);
		}
		str = br.readLine().split("");
		for (int j = 0; j < 8; j++) {
			J2[j] = Integer.parseInt(str[j]);
		}
		str = br.readLine().split("");
		for (int j = 0; j < 8; j++) {
			J3[j] = Integer.parseInt(str[j]);
		}
		str = br.readLine().split("");
		for (int j = 0; j < 8; j++) {
			J4[j] = Integer.parseInt(str[j]);
		}

		K = Integer.parseInt(br.readLine().trim()); // 회전 수
		// 자석 회전 진행
		for (int i = 0; i < K; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine().trim(), " ");

			N = Integer.parseInt(st.nextToken());
			rotate = Integer.parseInt(st.nextToken());

			checking(N, rotate);

		}

		score = 0;

		if (J1[0] == 1)
			score += 1;
		if (J2[0] == 1)
			score += 2;
		if (J3[0] == 1)
			score += 4;
		if (J4[0] == 1)
			score += 8;

		System.out.println(score);
	}

	public static void tfchk(int N) {
		chk1 = false;
		chk2 = false;
		chk3 = false;

		if (N == 1) {
			if (J1[2] != J2[6]) {
				chk1 = true;
			} else
				return;
			if (J2[2] != J3[6]) {
				chk2 = true;
			} else
				return;
			if (J3[2] != J4[6]) {
				chk3 = true;
			}
		} else if (N == 2) {

			if (J2[6] != J1[2]) {
				chk1 = true;
			}
			if (J2[2] != J3[6]) {
				chk2 = true;
			} else
				return;
			if (J3[2] != J4[6]) {
				chk3 = true;
			}

		} else if (N == 3) {

			if (J3[2] != J4[6]) {
				chk3 = true;
			}
			if (J3[6] != J2[2]) {
				chk2 = true;
			} else
				return;
			if (J2[6] != J1[2]) {
				chk1 = true;
			}

		} else {

			if (J4[6] != J3[2]) {
				chk3 = true;
			} else
				return;
			if (J3[6] != J2[2]) {
				chk2 = true;
			} else
				return;
			if (J2[6] != J1[2]) {
				chk1 = true;
			}

		}
	}

	public static void checking(int N, int rotate) {

		tfchk(N);

		if (N == 1) {
			if (rotate == 1) { // 시계
				if (!chk1 && !chk2 && !chk3) {
					rightRotate(J1);
				} else {
					if (chk1) {
						rightRotate(J1);
						leftRotate(J2);
						if (chk2) {
							rightRotate(J3);
							if (chk3) {
								leftRotate(J4);
							}
						}
					}
				}
			} else { // 반시계
				if (!chk1 && !chk2 && !chk3) {
					leftRotate(J1);
				} else {
					if (chk1) {
						leftRotate(J1);
						rightRotate(J2);
						if (chk2) {
							leftRotate(J3);
							if (chk3) {
								rightRotate(J4);
							}
						}
					}
				}
			}
		} else if (N == 2) {
			if (rotate == 1) { // 시계
				if (!chk1 && !chk2 && !chk3) {
					rightRotate(J2);
				} else {
					if (chk1) {
						rightRotate(J2);
						leftRotate(J1);
						if (chk2) {
							leftRotate(J3);
							if (chk3) {
								rightRotate(J4);
							}
						}
					} else {
						if (chk2) {
							rightRotate(J2);
							leftRotate(J3);
							if (chk3) {
								rightRotate(J4);
							}
						}
					}
				}
			} else { // 반시계
				if (!chk1 && !chk2 && !chk3) {
					leftRotate(J2);
				} else {
					if (chk1) {
						leftRotate(J2);
						rightRotate(J1);
						if (chk2) {
							rightRotate(J3);
							if (chk3) {
								leftRotate(J4);
							}
						}
					} else {
						if (chk2) {
							leftRotate(J2);
							rightRotate(J3);
							if (chk3) {
								leftRotate(J4);
							}
						}
					}
				}
			}
		} else if (N == 3) {

			if (rotate == 1) { // 시계
				if (!chk1 && !chk2 && !chk3) {
					rightRotate(J3);
				} else {
					if (chk3) {
						rightRotate(J3);
						leftRotate(J4);
						if (chk2) {
							leftRotate(J2);
							if (chk1) {
								rightRotate(J1);
							}
						}
					} else {
						if (chk2) {
							rightRotate(J3);
							leftRotate(J2);
							if (chk1) {
								rightRotate(J1);
							}
						}
					}
				}
			} else { // 반시계
				if (!chk1 && !chk2 && !chk3) {
					leftRotate(J3);
				} else {
					if (chk3) {
						leftRotate(J3);
						rightRotate(J4);
						if (chk2) {
							rightRotate(J2);
							if (chk1) {
								leftRotate(J1);
							}
						}
					} else {
						if (chk2) {
							leftRotate(J3);
							rightRotate(J2);
							if (chk1) {
								leftRotate(J1);
							}
						}
					}
				}
			}

		} else {
			if (rotate == 1) { // 시계
				if (!chk1 && !chk2 && !chk3) {
					rightRotate(J4);
				} else {
					if (chk3) {
						rightRotate(J4);
						leftRotate(J3);
						if (chk2) {
							rightRotate(J2);
							if (chk1) {
								leftRotate(J1);
							}
						}
					}
				}
			} else { // 반시계
				if (!chk1 && !chk2 && !chk3) {
					leftRotate(J4);
				} else {
					if (chk3) {
						leftRotate(J4);
						rightRotate(J3);
						if (chk2) {
							leftRotate(J2);
							if (chk1) {
								rightRotate(J1);
							}
						}
					}
				}
			}
		}

	}

	public static void leftRotate(int[] arr) { // 반시계
		int temp = arr[0];

		for (int i = 0; i < arr.length - 1; i++) {
			arr[i] = arr[i + 1];
		}

		arr[arr.length - 1] = temp;
	}

	public static void rightRotate(int[] arr) { // 시계
		int temp = arr[arr.length - 1];

		for (int i = arr.length - 1; i > 0; i--) {
			arr[i] = arr[i - 1];
		}

		arr[0] = temp;
	}

}
