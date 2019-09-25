#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int answer = 0, wordsize;
vector<int> answervector;
string beginword, targetword;
bool searchWord(string presentword, string word) {
	int count = 0; int size = word.size();
	for (int i = 0; i < size; i++) {
		if (word[i] != presentword[i])
			count++;
	}
	if (count == 1) return true;
	return false;
}
void dfs(int presentindex, vector<string> words, int index) {
	if (words[presentindex].compare(targetword) == 0) {
		answervector.push_back(answer);
		return;
	}
	else if (index == wordsize)
		return;
	else {
		for (int i = index; i < wordsize; i++) {
			if ((presentindex != -1 && searchWord(words[presentindex], words[i])) || searchWord(beginword, words[i])) {
				answer++;
				dfs(i, words, i + 1);
				answer--;
			}
		}
	}
}
int solution(string begin, string target, vector<string> words) {
	vector<string>::iterator it = find(words.begin(), words.end(), target);
	if (it != words.end()) {
		words.erase(it);
		words.push_back(target);
		cout << "\n";
		wordsize = words.size(); beginword = begin; targetword = target;
		dfs(-1, words, 0);
		sort(answervector.begin(), answervector.end());
		return answervector[0];
	}
	return 0;
}