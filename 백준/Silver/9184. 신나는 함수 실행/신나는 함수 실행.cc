#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

#define maxn    21
#define margin  50
#define NULLn    INT_MAX

using namespace std;

vector<vector<vector<int>>> dp(maxn, vector<vector<int>>(maxn, vector<int>(maxn, NULLn)));

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    if(a > 20 || b > 20 || c > 20){
        return w(20, 20, 20);
    }
    if(dp[a][b][c] != NULLn){
        return dp[a][b][c];
    }
    if(a < b && b < c){
        dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }else{
        dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
    return dp[a][b][c];
}

int main(){

    
    while(1){
        int a, b, c;
        cin >> a >> b >> c;

        if(a == -1 && b == -1 & c == -1){
            return 0;
        }
        cout << "w("<<a<<", "<<b<<", "<<c<<") = ";
        cout << w(a, b, c) << endl;
    }
    

    return 0;
}