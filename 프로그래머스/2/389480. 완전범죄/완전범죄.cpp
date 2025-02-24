#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;




int solution(vector<vector<int>> info, int n, int m) {
    
    if(info.size() == 1){
        if(info[0][1] < m) return 0; // b가 훔칠 수 있음
        if(info[0][0] < n) return info[0][0]; // b는 못훔치는데 a가 훔칠 수 있음
        return -1;// 둘 다 안됨
    }
    
    int answer = INT_MAX;
    
    vector<vector<int>> dp(info.size(), vector<int>(m, INT_MAX));
    // [i번째보물까지훔쳤을 때][b의 누적흔적] = a의 최소누적흔적;
    
    dp[0][0] = info[0][0]; // a만훔침
    dp[0][info[0][1]] = 0; // b만훔침
    
    for(int i = 1; i<info.size(); i++){
        for(int j = 0; j<m; j++){
            // a가 보물을 훔친다 == [][여기유지]
            // b는 안훔친다 == j유지
            if(dp[i-1][j] != INT_MAX){
                if(dp[i-1][j] + info[i][0] < n){
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + info[i][0]);
            // a가 훔쳤는데, n을 넘기면 안됨!!
                }
                
            }
            
            
            // b가 보물을 훔친다 == [i-1][j-info[i][1]] 인곳에서 왔음
            if(j-info[i][1] >= 0){
                dp[i][j] = min(dp[i][j], dp[i-1][j-info[i][1]]); //a의 흔적누적은 필요없음
            }
        }
    }
    
    
    answer = *min_element(dp[info.size()-1].begin(), dp[info.size()-1].end());
    
    if(answer >= n){
        answer = -1;
    }
    
    return answer;
}