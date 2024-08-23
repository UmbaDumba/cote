#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> dp(n, vector<int>(m, 1));
    
    for(int i = 0; i<puddles.size(); i++){
        dp[puddles[i][1]-1][puddles[i][0]-1] = 0;
    }
    
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(i == 0 && j == 0){
                continue;
            }
            if(dp[i][j] == 0){
                // 웅덩이!
                continue;
            }
            if(i == 0){
                dp[i][j] = dp[i][j-1];
                continue;
            }
            if(j == 0){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
        }
    }
    
    answer = dp[n-1][m-1];
    
    return answer;
}