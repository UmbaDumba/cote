#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// Compare two Foo structs.
bool comparevec(const vector<int>& x, const vector<int>& y) 
{
    return x[1] > y[1];
}

bool comparetime(const vector<int>& x, const vector<int>& y) 
{
    return x[0] < y[0];
}

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), comparetime); // 시간순 정렬
    
    int answer = 0;

    int sum = 0;
    int time = 0; // 지금 시간
    int iter = jobs.size();
    int do_job = 0; // 수행한 작업
    int get_index = 0; // 대기작업 가져오기를 한 index
    vector<vector<int>> can_jobs; // 지금 시점에서 수행가능한 작업들 == 대기목록
    
    while(true){
        if(do_job == iter){
            break;
        }
        
        // 지금 시점에서 수행 가능한 작업들 가져오기
        for(get_index; get_index<iter; get_index++){
            if(jobs[get_index][0] > time){
                get_index -= 0;
                break;
            }else{
                can_jobs.push_back(jobs[get_index]);
            }
        }
        make_heap(can_jobs.begin(), can_jobs.end(), comparevec); // 수행시간 기준으로 정렬
        
        
        if(can_jobs.size() < 1){
            // 지금시점에서 수행 가능한 작업들 가져오기를 했는데 비어있음 == 지금 할일이 없음
            time += 1;
            continue;
        }
        // 지금시점에서 수행 가능한 작업들이 있음!
    
        vector<int> now_job = can_jobs[0];
        pop_heap(can_jobs.begin(), can_jobs.end(), comparevec);
        can_jobs.pop_back();
        time += now_job[1];
        int exetime = time - now_job[0];
        sum += exetime;
        
        
        do_job += 1;
        
    }
    
    answer = sum / iter;
    
    
    return answer;
}