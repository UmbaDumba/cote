#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    
    vector<int> costs(n+1, -1);
    vector<vector<int>> edges(n+1);
    costs[1] = 0;
    
    for(int i = 0; i<edge.size(); i++){
        edges[edge[i][0]].push_back(edge[i][1]);
        edges[edge[i][1]].push_back(edge[i][0]);
    }
    
    vector<int> visited(n+1, 0);
    queue<int> que;
    que.push(1);
    visited[1] = 1;
    
    while(!que.empty()){
        int i = que.front();
        que.pop();
        
        
        for(int j = 0; j<edges[i].size(); j++){
            if(visited[edges[i][j]] == 1){
                continue;
            }
            que.push(edges[i][j]);
            visited[edges[i][j]] = 1;
            if(costs[edges[i][j]] == -1){
                costs[edges[i][j]] = costs[i] + 1;
            }else{
                costs[edges[i][j]] = min(costs[edges[i][j]], costs[i] + 1);
            }
        }
    }
        
    
    
    
    return count(costs.begin(), costs.end(), *max_element(costs.begin(), costs.end()));
}