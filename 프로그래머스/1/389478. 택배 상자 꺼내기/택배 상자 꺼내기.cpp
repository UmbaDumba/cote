#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    //1빼고 w로 나눴을 때 
    // 짝수면 오른쪽으로 증가
        // 제일 오른쪽이 w * (mod + 1)
        // 윗칸은 자기자신 + (((제일 오른쪽) - (자기자신)) * 2) + 1
    // 홀수면 왼쪽으로 증가
        // 제일 왼쪽이 w * (mod + 1)
        // 윗칸은 자기자신 + (((제일 왼쪽) - (자기자신)) * 2) + 1
    //          8     +    ((12 - 8)) * 2 + 1
    //         8 + 8 + 1 = 17
    
    int nowi = num;
    while(nowi <= n){
        answer++;
        
        nowi = (nowi + (((w * (((nowi-1) / w) + 1)) - nowi) * 2) + 1);
        
        
    }
    
    return answer;
}