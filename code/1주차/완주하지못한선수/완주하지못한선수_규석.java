package Programmers;

class 완주하지못한선수 {

    public final int HASH_SIZE = 1000;
    public final int HASH_LEN = 400;
    public final int HASH_VAL = 17;

    public String[][] s_data = new String[HASH_SIZE][HASH_LEN];
    public int[] cnt = new int[HASH_SIZE];

    public String solution(String[] participant, String[] completion) {
        String answer = "";

        for (int i = 0; i < completion.length; i++) {
            int key = getHashKey(completion[i]);
            s_data[key][cnt[key]++] = completion[i];
        }

        for (int i = 0; i < participant.length; i++) {

            int key = getHashKey(participant[i]);

            if(cnt[key] == 0) {
                return participant[i];
            }
            else {
                boolean chk = true;
                for (int j = 0; j < cnt[key]; j++) {
                    if(participant[i].equals(s_data[key][j])) {
                        s_data[key][j] = "";
                        chk = false;
                        break;
                    }
                }
                if(chk) {
                    return participant[i];
                }
            }
        }

        return answer;
    }

    public int getHashKey(String str) {
        int key = 0;

        for (int i = 0; i < str.length(); i++) {
            key = (key * HASH_VAL) + str.charAt(i);
        }

        if(key < 0) key = -key;

        return key % HASH_SIZE;
    }
}