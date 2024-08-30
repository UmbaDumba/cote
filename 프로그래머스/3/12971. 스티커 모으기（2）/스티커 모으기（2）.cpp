#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    
    if(sticker.size() == 1){
        return sticker[0];
    }else if(sticker.size() == 2){
        return max(sticker[0], sticker[1]);
    }

    // [0]을 부조건 뜯는경우
    vector<int> case1 = sticker;
    case1.pop_back();
    vector<int> dp1(case1.size(), case1[0]);
    for(int i = 2; i<case1.size(); i++){
        dp1[i] = max(dp1[i-1], dp1[i-2] + case1[i]);
    }
    
    // [0]을 안뜯는 경우
    vector<int> case2(sticker.begin()+1, sticker.end());
    vector<int> dp2(case2.size(), case2[0]);
    dp2[1] = max(dp2[0], case2[1]);
    for(int i = 2; i<case2.size(); i++){
        dp2[i] = max(dp2[i-1], dp2[i-2] + case2[i]);
    }
    
    answer = max(dp1[dp1.size()-1], dp2[dp2.size()-1]);
    
    return answer;
}