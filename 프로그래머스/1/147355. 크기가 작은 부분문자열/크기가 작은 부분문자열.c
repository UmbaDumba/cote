#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p) {
    int answer = 0;
    char t_cmp[20];
    
    //t,p의 길이를 받아와서 for 문 사용하여 t의 길이 - p의 길이까지 반복
    int t_len = strlen(t);
    int p_len = strlen(p);
    
    long long p_num = strtoll(p, NULL, 10);
    
    for ( int i = 0; i < t_len - p_len + 1; i++ )
    {
        strncpy(t_cmp,t+i,p_len);
        t_cmp[p_len] = 0;
        
        if(strtoll(t_cmp, NULL, 10) <= p_num)
        {
            answer++;
        }
    }

    return answer;

}