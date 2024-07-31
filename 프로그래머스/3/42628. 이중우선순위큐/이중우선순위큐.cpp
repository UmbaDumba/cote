#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    vector<int> max_que;
    vector<int> min_que;
    
    //q.erase(std::remove(q.begin(), q.end(), val), q.end());
    
    for(int i = 0; i<operations.size(); i++){
        string operation = operations[i];
        stringstream ss(operation);
        char inst;
        int num;
        ss >> inst;
        ss >> num;
        switch(inst){
            case 'I':
                max_que.push_back(num);
                push_heap(max_que.begin(), max_que.end());
                min_que.push_back(num);
                push_heap(min_que.begin(), min_que.end(), greater<>{});
                break;
            case 'D':
                if(num == 1){
                    if(!max_que.empty()){
                        int max = max_que[0];
                        pop_heap(max_que.begin(), max_que.end());
                        max_que.pop_back();
                        min_que.erase(remove(min_que.begin(), min_que.end(), max), min_que.end());
                    }
                }else{
                    if(!min_que.empty()){
                        int min = min_que[0];
                        pop_heap(min_que.begin(), min_que.end(), greater<>{});
                        min_que.pop_back();
                        max_que.erase(remove(max_que.begin(), max_que.end(), min), max_que.end());
                    }
                    
                }
        }
    }
    
    if(max_que.empty()){
        answer = {0,0};
    }else{
        answer = {max_que[0], min_que[0]};
    }
    
    
    return answer;
}