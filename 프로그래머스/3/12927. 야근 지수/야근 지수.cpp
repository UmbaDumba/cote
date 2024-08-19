#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> myque;
    
    for(int i = 0; i<works.size(); i++){
        myque.push(works[i]);
    }
    
    for(int i = 0; i<n; i++){
        int num = myque.top();
        if(num == 0){
            return 0;   
        }
        myque.pop();
        num--;
        myque.push(num);
        
    }
    
    for(int i = 0; i<works.size(); i++){
        answer += (long long)myque.top() * (long long)myque.top();
        myque.pop();
    }
    return answer;
}