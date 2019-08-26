#include <string>
#include <vector>
#include <queue>

using namespace std;

class Data{
public :
    int date;
    int supply;
};

class Supllies_compare {
public :
    bool operator() (const Data * lhs, const Data * rhs){
        return (lhs -> supply) < (rhs -> supply);
    }
};

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int time = 0;
    
    Data *  data ; 
    queue<Data *> data_queue ;
    priority_queue<Data * , vector<Data *> , Supllies_compare> supply_pq;
    
    for(vector<int>::size_type i = 0 ; i < dates.size(); i ++){
        data = new Data();
        data -> date = dates[i];
        data -> supply = supplies[i];
        
        data_queue.push(data);
    }
    
    while(true){
        while(data_queue.front() -> date <= stock){
            data = data_queue.front();
            data_queue.pop();
            supply_pq.push(data);
        }

        data = supply_pq.top();
        stock += data -> supply;

        if(stock < k){
            answer ++;
        }
        else{
            break;
        }

    }
    
  
    
    return answer;
}