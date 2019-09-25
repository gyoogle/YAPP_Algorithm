public class 단어변환 {
	
	static int min = Integer.MAX_VALUE;
	static char[] ch;
	
	public static int solution(String begin, String target, String[] words) {
		
		boolean isTrue = false;
		for (int i = 0; i < words.length; i++) {
			if(target.equals(words[i])) {
				isTrue = true;
				break;
			}
		}
		if(!isTrue) return 0;
		
		boolean[] visited = new boolean[words.length];
		dfs(begin, target, words, visited, 0);
		
		return min;
	}
	
	public static void dfs(String begin, String target, String[] words, boolean[] visited, int cnt) {
		
		//출발점과 idx가 일치하면 끝
		if(begin.equals(target)) {
			if(min > cnt) {
				min = cnt;
				return;
			}
		}
		
		for (int i = 0; i < words.length; i++) {
			if(visited[i]) continue;
			ch = words[i].toCharArray();
			int count = 0;
			for (int j = 0; j < ch.length; j++) {
				if(begin.charAt(j) == ch[j]) count++;
			}
			if(count >= begin.length()-1) {
				visited[i] = true;
				dfs(words[i], target, words, visited, cnt+1);
				visited[i] = false;
			}
		}
		
	}

	public static void main(String[] args) {
		String begin = "hit";
		String target = "cog";
		
		String[] words = {"hot", "kkk", "dog", "lot", "lop", "cop", "cot", "top", "cog"};
		
		System.out.println(solution(begin, target, words));
	}

}
