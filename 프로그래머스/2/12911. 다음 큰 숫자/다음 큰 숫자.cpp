#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = n;
    int isone = 1;
    int num = 1;
    
    while(true)
    {
        if(n % 2 == 1){
            isone*=2;
            answer -= num;
        }else if(isone > 1 && n % 2 == 0)
        {
            return answer + num + (isone / 2 - 1);
        }
        
        num *= 2;
        n /= 2;
    }
    
}