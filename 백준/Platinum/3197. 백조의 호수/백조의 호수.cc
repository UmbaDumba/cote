#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dx = {1, 0 ,-1, 0};
vector<int> dy = {0, 1, 0, -1};

int r, c;
vector<vector<bool>> maps;
vector<vector<bool>> visited;

vector<vector<int>> backs;

queue<vector<int>> water;
queue<vector<int>> back;


bool melt_meet(){
    // 만나러 가는 동시에 녹이기

    // 백조가 지금 위치에서 도달할수있는곳까지 큐에 넣기
    queue<vector<int>> next_back;
    while(!back.empty()){
        int x = back.front()[0];
        int y = back.front()[1];
        back.pop();

        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                continue;
            }

            // 만난상황
            if(nx == backs[1][0] && ny == backs[1][1]){
                return true;
            }

            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                if(maps[nx][ny]){
                    // 얼음인곳
                    next_back.push({nx, ny});
                }else{
                    // 물인곳
                    back.push({nx, ny});
                }
            }
        }
    }
    back = next_back;

    // 얼음 녹이기
    // 큐에 넣어둔 물을 탐색하면서, 다음얼음을 만나면 녹이기
    queue<vector<int>> next_water;
    while(!water.empty()){
        int x = water.front()[0];
        int y = water.front()[1];
        water.pop();

        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                continue;
            }


            if(maps[nx][ny]){
                // 얼음인곳
                next_water.push({nx, ny});
                maps[nx][ny] = false;
            }else{
                // 물인곳 == 아무것도 할필요 없음
            }
            
        }        
    }

    water = next_water;


    return false;
}

int main(){

    
    cin >> r >> c;

    maps = vector<vector<bool>>(r, vector<bool>(c, false));
    visited = vector<vector<bool>>(r, vector<bool>(c, false));
    

    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            char temp;
            cin >> temp;

            if(temp == 'X'){
                maps[i][j] = true;
            }else{
                water.push({i, j});
            }
            
            if(temp == 'L'){
                backs.push_back({i, j});
            }
        }
    }
    
    back.push({backs[0][0], backs[0][1]});
    visited[backs[0][0]][backs[0][1]] = true;


    
    int days = 0;

    while(true){
        if(melt_meet()){
            break;
        }
        days++;
    }

    cout << days;
  

    return 0;
}