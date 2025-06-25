#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solution(string s)
{
    int answer = 1;
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    
    for(int i = 0; i<s.size(); i++)
    {
        dp[i][i] = true;
    }
    
    for(int i = 0; i<s.size()-1; i++)
    {
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = true;
            answer = 2;
        }
    }
    
    for(int i = 2; i<s.size(); i++) // i : length - 1
    {
        for(int j = 0; j<s.size() - i; j++)
        {
            if(s[j] == s[j+i]){
                dp[j][j+i] = dp[j+1][j+i-1];
                if(dp[j][j+i])
                {
                    answer = max(answer, i+1);
                }
            }
        }
    }
    
    
    
    return answer;
}