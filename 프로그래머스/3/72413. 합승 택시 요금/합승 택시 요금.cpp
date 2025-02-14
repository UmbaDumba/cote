#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

vector<vector<int>> cost;

vector<long long> min_cost(int s, int n){
    vector<long long> result(n+1, LONG_MAX);
    vector<bool> check(n+1, false);
    int limit = n;
    
    result[s] = 0;
    check[s] = true;
    limit--;
    
    while(limit > 0){
        // 지금위치에서 갈수있는곳들 업데이트
        for(int i = 1; i<=n; i++){
            if(cost[s][i] == 0){
                continue;
            }
            result[i] = min(result[i], result[s] + (long long)cost[s][i]);
        }
        
        // 다음위치 찾기 (최소값을 가지는친구)
        int next;
        long long next_cost = LONG_MAX;
        for(int i = 1; i<=n; i++){
            if(check[i]){
                continue;
            }
            if(next_cost > result[i]){
                next = i;
                next_cost = result[i];
            }
        }
        limit--;
        s = next;
        check[s] = true;
        
    }
    return result;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    cost = vector<vector<int>>(n+1, vector<int>(n+1, 0));
    
    for(int i = 0; i<fares.size(); i++){
        cost[fares[i][0]][fares[i][1]] = fares[i][2];
        cost[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    vector<long long> stohap = min_cost(s, n);
    vector<long long> atohap = min_cost(a, n);
    vector<long long> btohap = min_cost(b, n);
    
    long long result = LONG_MAX;
    
    for(int i = 1; i<=n; i++){
        if(stohap[i] == LONG_MAX || atohap[i] == LONG_MAX || btohap[i] == LONG_MAX){
            continue;
        }
        long long temp = stohap[i] + atohap[i] + btohap[i];
        result = min(result, temp);
    }
    
    return result;
}