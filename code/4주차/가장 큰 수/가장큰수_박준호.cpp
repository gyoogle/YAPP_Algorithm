#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Mutation{
public :
    int mutated;
};


bool operator <(const Mutation &a, const Mutation &b){
    // a.mutated > b.mutated
    if(a.mutated ==  b.mutated)
        return false;
    if(a.mutated == 0){
        return false;
    }
    if(b.mutated == 0){
        return true;
    }
    else{
        int aM, bM, j;
        
        aM = a.mutated;
        bM = b.mutated;
        
        j = b.mutated;
        while(j > 0){
            aM *= 10;
            j /= 10;
        }
        aM += b.mutated;
        
        j = a.mutated;
        
        while(j > 0){
            bM *= 10;
            j /= 10;
        }
        bM += a.mutated;

        
        return aM > bM;
    }
};

string solution(vector<int> numbers) {
    string answer = "";
    vector<Mutation> mutations ;
    bool zero = true;
    
    for(vector<int>::size_type i = 0 ; i < numbers.size(); i ++){
        Mutation * m = new Mutation();
        m -> mutated = numbers[i];
        mutations.push_back(*m);
    }
    

    sort(mutations.begin(), mutations.end());
    
    //순서대로  string으로 변환
    for(vector<Mutation>::size_type i = 0 ; i < mutations.size(); i ++){
        answer += to_string(mutations[i].mutated);
        
        if(mutations[i].mutated != 0){
            zero = false;
        }
    }
    
    if(zero == true){
        return "0";
    }
    return answer;
}