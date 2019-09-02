#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int solution(vector<int> citations) {
    
    sort(citations.begin(), citations.end());
    
    for(vector<int>::size_type i = 0 ; i < citations.size(); i ++){
        if(citations[i] >= citations.size() - i)
            return citations.size()  - i;
    }
    
    return 0;
}