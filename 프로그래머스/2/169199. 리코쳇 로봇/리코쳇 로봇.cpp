#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;

int n, m;
vector<vector<int>> myboard;
pair<int, int> endpoint;
int steps = INT_MAX;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

pair<int, int> gogo(int x, int y, int direction){
    int newx = x;
    int newy = y;
    while(true){
        int nextx = newx + dx[direction];
        int nexty = newy + dy[direction];
        if(nextx < 0 || nextx >= n || nexty < 0 || nexty >= m){
            break;
        }
        if(myboard[nextx][nexty] == 1){
            break;
        }
        newx = nextx;
        newy = nexty;
    }
    return {newx, newy};
}

int solution(vector<string> board) {
    
    int answer = 0;
    
    n = board.size();
    m = board[0].size();
    
    myboard = vector<vector<int>>(n, vector<int>(m, 0));
    queue<vector<int>> que; // x, y, count
    
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[i].size(); j++){
            if(board[i][j] == 'D'){
                myboard[i][j] = 1;
            }else if(board[i][j] == 'R'){
                myboard[i][j] = 0;
                que.push({i, j, 0});
            }else if(board[i][j] == 'G'){
                myboard[i][j] = 0;
                endpoint = {i, j};
            }else{
                myboard[i][j] = 0;
            }
        }
    }
    
    
    
    while(!que.empty()){
        vector<int> indexx = que.front();
        que.pop();
        if(indexx[0] == endpoint.first && indexx[1] == endpoint.second){
            // 끝에 도착!
            return indexx[2];
        }
        for(int i = 0; i<4; i++){
            pair<int, int> newindex = gogo(indexx[0], indexx[1], i);
            if(newindex.first == indexx[0] && newindex.second == indexx[1]){
                // index가 그대로 == 이 방향으로는 이동 못함!
                continue;
            }
            if(myboard[newindex.first][newindex.second] == -1){
                // 이미 방문해본곳
                // 더이상 진행xx
                continue;
            }
            //cout << newindex.first<<", "<<newindex.second<<", "<<indexx[2]<<endl;
            myboard[newindex.first][newindex.second] = -1;
            que.push({newindex.first, newindex.second, indexx[2]+1});
        }
    }
    
    
    
    
    return -1;
}