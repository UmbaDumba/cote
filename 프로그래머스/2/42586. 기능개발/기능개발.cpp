#include <string>
#include <vector>
#include <queue>

using namespace std;

// 길이가 같은 두 벡터끼리 더해주는것 (같은 위치끼리)
vector<int> vec_add(vector<int> a, vector<int> b){
    vector<int> result;
    for(int i = 0; i<a.size(); i++){
        result.push_back(a[i] + b[i]);
    }
    return result;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> proc_que;
    
    for(int i = 0; i<progresses.size(); i++){
        proc_que.push(i);
    }
    
    int how_days = 0;
    int ends = 0;
    while(!proc_que.empty()){
        int i = proc_que.front();
        if((progresses[i] + (speeds[i] * how_days)) >= 100){
            ends++;
            proc_que.pop();
            continue;
        }
        if(ends != 0){
            answer.push_back(ends);
            ends = 0;
        }
        how_days++;
        
    }
    if(ends != 0){
        answer.push_back(ends);
    }
    
    
    
    return answer;
}