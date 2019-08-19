public class 프린터_개선_규석 {

	static boolean[] prio = new boolean[10]; // 1~9 priority max 값 찾기 위한 배열
	static int[] max; // 중복되지 않는 max 값 저장
	static int index;

	static boolean[] arr; // priorities 배열의 해당 위치마다 인쇄 유무 저장
	static int[] res; // priorities 배열의 해당 인덱스의 인쇄 순서 저장
	static int start, chk;

	public static int solution(int[] priorities, int location) {
		index = 0;

		for (int i = 0; i < priorities.length; i++) {
			if (prio[priorities[i]])
				continue; // 이미 저장된 우선순위면 continue

			prio[priorities[i]] = true;
			index++; // 우선순위 개수 증가
		}

		max = new int[index]; // 개수만큼 max 배열 선언
		index = 0;
		for (int i = prio.length - 1; i > 0; i--) {
			if (prio[i])
				max[index++] = i;
		}
		// max 배열에 가장 큰 우선순위 값부터 저장

		index = start = 0;
		int resIdx = 1; // 인쇄 순서 값
		arr = new boolean[priorities.length];
		res = new int[priorities.length];

		while (true) {

			// 인덱스가 max 배열 넘어가면 종료
			if (index > max.length - 1)
				break;

			// 현재 가장 큰 우선순위 값
			int maxPrio = max[index];

			// 현재 위치 인덱스(start)부터 배열 끝까지 탐색
			for (int i = start; i < priorities.length; i++) {
				if (priorities[i] == maxPrio && !arr[i]) { // 최고 우선 순위가 일치하고 아직 인쇄되지 않은 곳이면

					arr[i] = true;
					// if(location == i) {
					// return resIdx;
					// }
					res[i] = resIdx++; // 인쇄 순서 저장
					chk = i; // 다음 인쇄부터 시작할 인덱스 저장
				}
			}

			int temp = chk;
			if (index >= 1) { // 한번 진행한 이후는 다시 첫 인덱스로 돌아가서 확인해야함
				for (int i = 0; i < chk; i++) {
					if (priorities[i] == maxPrio && !arr[i]) { // 최고 우선 순위 면

						arr[i] = true;
						// if(location == i) {
						// return resIdx;
						// }
						res[i] = resIdx++; // 인쇄값 저장
						temp = i; // 다음 인쇄부터 시작할 인덱스 저장
					}
				}
			}

			start = temp; // start에 다음에 인쇄할 인덱스 갱신
			index++; // 다음 우선순위 탐색을 위해 index 값 증가
		}

		// location에 맞는 인쇄 순서 리턴
		return res[location];
	}

	public static void main(String[] args) {

		int[] priorities = { 2, 2, 2, 1, 3, 4 };
		int location = 0;

		System.out.println(solution(priorities, location));

	}

}
