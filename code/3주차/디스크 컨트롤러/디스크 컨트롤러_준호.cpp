#include <string>
#include <vector>
#include <queue>

using namespace std;

class Request_compare
{
public:
    bool operator() (const vector<int> &lhs, const vector<int> &rhs)
    {
        return lhs[0] > rhs[0];
    }
};

class Time_compare
{
public:
    bool operator() (const vector<int> &lhs, const vector<int> &rhs)
    {
        return lhs[1] > rhs[1];
    }
};


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, Request_compare> request_pq ;
    priority_queue<vector<int>, vector<vector<int>>, Time_compare> time_pq;
    
    int time = 0;
    
    vector<int> job;
    
    //요청한 시각이 빠를수록 먼저 호출되도록 pq에 정렬
    for(vector<int>::size_type i = 0 ; i < jobs.size(); i ++){
        request_pq.push(jobs[i]);
    }
    
    while(true){
        //현재 시간(time) 에서 처리할 수 있는 작업들을 불러오고, time_pq에 삽입
        while(
            !request_pq.empty() &&
            (job=request_pq.top())[0]  <= time ) {   

            request_pq.pop();

            time_pq.push(job);
        }
        
        if(time_pq.empty()){
            time = request_pq.top()[0];
        }
        else{
            //대기시간(요청~종료) 시간이 제일 짧은 작업을 불러옴
            job = time_pq.top();    
            time_pq.pop();

            answer += (time - job[0]) + job[1];

            time += job[1];
        }
        
        if(request_pq.empty() && time_pq.empty()){
            break;
        }
    }
    
    
    return answer / jobs.size();
}