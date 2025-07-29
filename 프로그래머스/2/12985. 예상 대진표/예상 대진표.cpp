#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    while(1){
        if(a < b){
            if(b - a == 1){
                if(b % 2 == 0){
                    // 만남
                    return answer;
                }
            }
            
        } else {
            if(a - b == 1){
                if(a % 2 == 0){
                    // 만남
                    return answer;
                }
            }
            
        }
        
        // 다음라운드로 올라가야함
        a = (a / 2) + (a % 2);
        b = (b / 2) + (b % 2);
        answer++;
    }

    return answer;
}