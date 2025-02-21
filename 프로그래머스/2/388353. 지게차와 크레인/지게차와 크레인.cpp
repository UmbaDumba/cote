#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int solution(vector<string> storage, vector<string> requests) {
    int answer = (int)storage.size() * (int)storage[0].size();
    
    string emptys((int)storage[0].size(), 'e');
    storage.insert(storage.begin(), emptys);
    storage.push_back(emptys);
    
    for(int i = 0; i<storage.size(); i++){
        storage[i].insert(0, "e");
        storage[i].push_back('e');
    }
    
    
    
    for(int i = 0; i<requests.size(); i++){
        if(requests[i].size()>1){
            // 크레인
            //cout << "ccccc"<<endl;
            for(int j = 0; j<storage.size(); j++){
                for(int k = 0; k<storage[0].size(); k++){
                    if(storage[j][k] == requests[i][0]){
                        storage[j][k] = 'e';
                        answer--;
                    }
                }
            }
        }else{
            // 지게차
            vector<string> visit = storage;
            queue<vector<int>> que;
            que.push({0, 0});
            visit[0][0] = 'v';
            while(!que.empty()){
                int x = que.front()[0];
                int y = que.front()[1];
                que.pop();
                for(int j = 0; j<4; j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(nx < 0 || nx >= storage.size() || ny < 0 || ny >= storage[0].size()){
                        continue;
                    }
                    if(visit[nx][ny] != 'v'){
                        visit[nx][ny] = 'v';
                        if(storage[nx][ny] == 'e'){
                            que.push({nx, ny});
                        }else if(storage[nx][ny] == requests[i][0]){
                            storage[nx][ny] = 'e';
                            answer--;
                        }
                    }
                }
            }
        }
        
        
    }
    
    return answer;
}