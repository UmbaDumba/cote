#include <string>
#include <vector>
#include <iostream>

#define SOL_TIME(diff, level, time_cur, time_prev) diff <= level ? time_cur : (diff - level) * (time_cur + time_prev) + time_cur

using namespace std;


long long get_puzzle_sol_time(vector<int> diffs, vector<int> times, int level)
{
    long long result = 0;
    for(int i = 0; i<diffs.size(); i++){
        long long puzz = SOL_TIME(diffs[i], level, times[i], (i == 0 ? 0 : times[i-1]));
        result += puzz;
    }
    
    return result;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int level_max = 100000;
    int level_min = 1;
    int level;
    
    
    while(level_max > level_min){
        level = (level_max + level_min) / 2;
        
        long long puzzle_time = get_puzzle_sol_time(diffs, times, level);
        if(puzzle_time > limit){
            level_min = level + 1;
        }else{
            level_max = level;
        }
    }

    return (level_max + level_min) / 2;
}