#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> part_map;
    
    for(vector<string>::size_type i = 0 ; i < participant.size() ; i ++){
        string &name = participant[i] ;
        
        if(part_map.find(name) == part_map.end()){
            part_map.insert(pair<string &,int>(name, 1));
        }
        else{
            part_map[name] += 1;
        }
    }
    
     for(vector<string>::size_type i = 0 ; i < completion.size() ; i ++){
        string &name = completion[i];
         
         part_map[name] --;
         
         if(part_map[name] == 0){
             part_map.erase(name);
         }
     }
    
     return part_map.begin() -> first;
}