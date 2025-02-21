#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i = 0; i<schedules.size(); i++){
        bool flag = true;
        int sday = startday - 1;
        for(int j = 0; j<7; j++){
            sday++;
            sday %= 7;
            if(sday == 6 || sday == 0){
                // 주말 == 취급안함
                continue;
            }
            int stime = ((schedules[i] / 100) * 60) + (schedules[i] % 100);
            int ltime = ((timelogs[i][j] / 100) * 60) + (timelogs[i][j] % 100);
            if(ltime - stime > 10){
                // 10분 넘게 지각 (더 일찍 도착한 경우는 음수가 나와서 여기에 안걸림)
                flag = false;
                break;
            }
        }
        if(flag){
            answer++;
        }
    }
    
    return answer;
}