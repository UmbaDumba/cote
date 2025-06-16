#include <iostream>
#include <vector>

using namespace std;

int main(){

    int T;
    cin >> T;

    vector<vector<int>> dp;   // [i] : i일 때 경우의수
                             //  [i][0] : 1만 사용
                             //  [i][1] : 2를 반드시 포함하여 1과 2만 사용
                             //  [i][2] : 3을 반드시 포함하여 1, 2, 3 전부 사용
    dp.push_back({1, 0, 0}); // [0]은 사용안해서 임의값 넣어두기
    dp.push_back({1, 0, 0}); // 1
    dp.push_back({1, 1, 0}); // 1 + 1     2
    dp.push_back({1, 1, 1}); // 1 + 1 + 1     1 + 2     3

    for(int i = 0; i<T; i++){
        int n;
        cin >> n;
        
        // dp 업데이트
        while(dp.size() <= n){
            int m = dp.size(); // 하나씩 추가하기

            // 1만 사용 == 1개뿐
            vector<int> tmp(3);
            tmp[0] = 1;

            // 2를 반드시 사용
            // 2 * k + (1로 만든 숫자, 혹은 0) 밖에 없음
            // == k가 곧 2를 반드시 사용하는 상황에서의 경우의수
            tmp[1] = m / 2;

            // 3을 반드시 사용
            // 3 * k + (1, 2만 사용한 숫자)
            tmp[2] = 0;
            int max_i = m / 3;
            for(int i = 1; i <= max_i; i++){
                tmp[2] += (dp[m - (i * 3)][0] + dp[m - (i * 3)][1]);
            }

            // dp에 넣기
            dp.push_back(tmp);
        }
        
        cout << dp[n][0] + dp[n][1] + dp[n][2] << endl;

    }

    return 0;
}