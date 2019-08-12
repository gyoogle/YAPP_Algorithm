package Programmers;

class ��ȭ��ȣ��� {
    
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

            //������ �ܾ� ������ false ����
            if(end) return false;

            //idx�� str��ŭ ������
            if(idx == str.length()) {
                end = true;
                if(pass) return false; // �� �������� �ܾ� ������ false ����
                else return true;
            }
            //���� �ȿ��� ��
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