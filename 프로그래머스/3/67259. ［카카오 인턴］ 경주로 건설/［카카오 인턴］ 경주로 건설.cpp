#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> maps;
vector<vector<vector<int>>> dp; // [x][y][dir]

int n;

vector<int> dx = {-1, 0, 1, 0}; // 상 우 하 좌
vector<int> dy = {0, 1, 0, -1};

void dfs(int x, int y, int pre_dir, int cost)
{
    if((x == n-1) && (y == n-1))
    {
        //answer = min(answer, cost);
        return;
    }
    
    for(int i = 0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
        {
            continue;
        }
        
        
        if(pre_dir == i)
        {
            if(maps[nx][ny] == 0)
            {
                if(dp[nx][ny][i] > (cost + 1))
                {
                    dp[nx][ny][i] = cost+1;
                    dfs(nx, ny, i, cost+1);
                }
                
            }
        }else if(abs(pre_dir - i) != 2){
            if(maps[nx][ny] == 0)
            {
                if(dp[nx][ny][i] > (cost + 6))
                {
                    dp[nx][ny][i] = cost+6;
                    dfs(nx, ny, i, cost+6);
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    maps = board;
    n = board.size();
    dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(4, INT_MAX)));
    
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    dp[0][0][2] = 0;
    dp[0][0][3] = 0;
    
    dfs(0, 0, 2, 0);
    dfs(0, 0, 1, 0);
    
    
    return (*min_element(dp[n-1][n-1].begin(), dp[n-1][n-1].end())) * 100;
}