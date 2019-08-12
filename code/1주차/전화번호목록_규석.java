package Programmers;

class 전화번호목록 {
    
    static class Trie {
        boolean end;
        boolean pass;
        Trie[] child;

        Trie() {
            end = false;
            pass = false;
            child = new Trie[10];
        }

        public boolean insert(String str, int idx) {

            //끝나는 단어 있으면 false 종료
            if(end) return false;

            //idx가 str만큼 왔을때
            if(idx == str.length()) {
                end = true;
                if(pass) return false; // 더 지나가는 단어 있으면 false 종료
                else return true;
            }
            //아직 안왔을 때
            else {
                int next = str.charAt(idx) - '0';
                if(child[next] == null) {
                    child[next] = new Trie();
                    pass = true;
                }
                return child[next].insert(str, idx+1);
            }

        }
    }
    
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        Trie trie = new Trie();
        
        for (int i= 0; i < phone_book.length; i++) {
            if(!trie.insert(phone_book[i], 0)){
                return false;
            }
        }
        return answer;
    }
}