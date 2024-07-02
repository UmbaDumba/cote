#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int> > computers) {
    int answer = 0;
    
    vector<int> computerss(n, 1);
    bool flag = true;
    
    int seed = 0;
    
    while(flag){
        if(find(computerss.begin(), computerss.end(), 1) == computerss.end()){
            break;
        }
        for(int i = 0; i<n; i++){
            if(computerss[i] == 1){
                seed = i;
                break;
            }
        }
        queue<int> que;
        que.push(seed);
        
        while(!que.empty()){
            int computer = que.front();
            que.pop();
            computerss[computer] = 0;
            for(int i = 0; i<n; i++){
                if(i != computer){
                    if(computers[computer][i] == 1){
                        que.push(i);
                        computers[computer][i] = 0;
                    }
                }
            }
        }
        answer++;
        
        
    }
    
    return answer;
}