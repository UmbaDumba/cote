#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    vector<long long> dp(n+1,0);
    
    dp[0] = 1; // 출발선 (칸 위에 아님)
    dp[1] = 1; // [0] 에서 점프하는 한가지만 가능
    
    for(int i = 2; i<n+1; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
            //   1칸점프     2칸점프
        
    }
    
    return dp[n];
}