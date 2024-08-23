#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());
    
    
    int j = 0; // B index
    for(int i = 0; i<A.size(); i++){
        if(A[i] < B[j]){
            // win
            answer++;
            j++;
        }
        // 지거나 비김
        // 아무것도 할필요가 없음 (j 그대로)
    }
    
    return answer;
}