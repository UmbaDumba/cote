#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b) {
    
    // 문자열 합치기
    char ab[10], ba[10];
    sprintf(ab, "%d%d", a, b);
    sprintf(ba, "%d%d", b, a);
    
    // 합친 문자열을 숫자로 바꾸기
    int ab_num, ba_num;
    ab_num = atoi(ab);
    ba_num = atoi(ba);
    
    // 두개 중 더 큰것 고르기
    if(ab_num >= ba_num) return ab_num;
    else                 return ba_num;
    
}