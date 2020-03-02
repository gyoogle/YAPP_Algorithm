#include <string>
#include <vector>
#include <queue> 
#include <unordered_map>
#include <regex>
#include <iterator>
#include <iostream>

using namespace std;

string get_next_token(sregex_iterator it){
    smatch match = *it;
    string match_str = match.str();
    return match_str;
}

void read_column(string column , queue<int>& msg_queue, queue<string>& uid_queue, unordered_map<string,string>& nickname_table){
    string msg_type , uid, nickname;
    
    regex word_regex("[^\\s]+");
    sregex_iterator it = sregex_iterator(column.begin(), column.end(), word_regex); 
    sregex_iterator end = sregex_iterator();
    
    msg_type = get_next_token(it);
    uid = get_next_token(++it);
    

    if(msg_type != "Change"){
        msg_queue.push(msg_type == "Enter" ? 1 : 0);
        uid_queue.push(uid);
    }
    
    if(msg_type != "Leave"){
        nickname = get_next_token(++it);
        nickname_table[uid] = nickname;
    }
    
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    queue<int> msg_type_queue;
    queue<string> uid_queue;
    unordered_map<string, string> nickname_table;
    
    for(auto it = record.begin() ; it != record.end() ; it ++){
        read_column(*it , msg_type_queue, uid_queue, nickname_table);
    }
    
    
    while(!msg_type_queue.empty()){
        string msg = "";
        int msg_type = msg_type_queue.front();
        string uid = uid_queue.front();
        
        msg += nickname_table[uid];
        msg += "님이 ";
        msg += msg_type ? "들어왔습니다." : "나갔습니다.";
            
        msg_type_queue.pop();
        uid_queue.pop();
        
        answer.push_back(msg);
    }
    
    
    return answer;
}
