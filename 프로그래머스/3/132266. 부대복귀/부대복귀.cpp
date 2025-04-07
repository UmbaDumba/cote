#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer(n, -1);
    queue<vector<int>> que; // [index, len]
    
    destination--;
    
    que.push({destination, 0});
    answer[destination] = 0;
    
    vector<vector<int>> maps(n);
    
    for(int i = 0; i<roads.size(); i++)
    {
        maps[roads[i][0]-1].push_back(roads[i][1] - 1);
        maps[roads[i][1] - 1].push_back(roads[i][0]-1);
    }
    
    
    // bfs
    while(!que.empty())
    {
        vector<int> node = que.front();
        que.pop();

        for(int i = 0; i<maps[node[0]].size(); i++)
        {
            if(answer[maps[node[0]][i]] == -1)
            {
                // 갈 수 있고 간적 없을 때
                answer[maps[node[0]][i]] = node[1] + 1;
                que.push({maps[node[0]][i], node[1] + 1});
            }
        }
    }
    
    // answer : 각 노드로부터 destination까지 걸리는 거리
    
    vector<int> result(sources.size());
    
    for(int i = 0; i<sources.size(); i++)
    {
        result[i] = answer[sources[i] - 1];
    }
    
    return result;
}