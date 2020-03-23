#include <bits/stdc++.h>
#include <unordered_map>
#include <string.h>

using namespace std;

int insert_anagram_map(unordered_map<string, int>& anagram_map, string& s , int start, int end){

    string letter_anagram = "";
    
    char letters[30] = {0};
    memset(letters, 0 , sizeof(letters));

    for(auto it = s.begin() + start ; it != s.begin() + end ; it ++){
        letters[*it - 'a'] ++;
    }

    for(int i = 0; i< 30 ; i ++){
        if(letters[i] > 0){
            letter_anagram += (i + 'a');
        }

        if(letters[i] > 1){
            letter_anagram += letters[i] ;
        }
        
    }

    //cout << letter_anagram << "\n";

    if(anagram_map.find(letter_anagram) != anagram_map.end()){
        anagram_map[letter_anagram] ++;

        return anagram_map[letter_anagram] - 1;
    }
    else{
        anagram_map[letter_anagram] = 1;

        return 0;
    }


}


// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    unordered_map<string, int> anagram_map;
        
    int size = s.size();
    int res = 0;

    for(int n = 1 ; n < size ; n ++){
        for(int i = 0 ; i < size - n + 1 ; i ++){
            res += insert_anagram_map(anagram_map, s, i, i + n);
            //cout << i << " " << i + n <<  " " << res << "\n" ;
        }
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
