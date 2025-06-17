#include <iostream>
#include <vector>
using namespace std;

int solution(int n)
{
    int ans = 0;
    int tmp = n;
    
    while(1){
        if(tmp == 0) break;
        
        if(tmp % 2 == 1){
            // 홀수거리는 순간이동으로 불가능, 무조건 바로전(짝수)에서 점프를 해야함
            ans++;
            tmp--;
            continue;
        }else{
            // 짝수거리는 그냥 순간이동으로 오는게 젤 가성비
            tmp /= 2;
            continue;
        }
        
    }

    return ans;
}