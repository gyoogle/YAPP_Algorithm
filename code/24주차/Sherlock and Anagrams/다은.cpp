#include <bits/stdc++.h>
using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int answer = 0;
    unordered_map<string,int> anagramHash;
    for(int i = 0; i < s.length(); i++){
        string presentString = "";
        for(int j = i; j < s.length(); j++){
            presentString += s[j];
            sort(presentString.begin(),presentString.end());
            unordered_map<string,int> :: iterator anagramIter = anagramHash.find(presentString);
            if(anagramHash.size() > 0 && anagramIter != anagramHash.end()){
                int num = anagramIter->second;
                answer+= num;
                anagramHash.erase(presentString);
                anagramHash.insert(make_pair(presentString,num+1));
            }
            else
                anagramHash.insert(make_pair(presentString,1));
        }
    }
    return answer;
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
