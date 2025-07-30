#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1);
    
    for(int i = 0; i<answer.size(); i++){
        long long j = left + i;
        long long a = j / n;
        long long b = j % n;
        
        if(b > a) answer[i] = b + 1;
        else answer[i] = a + 1;
    }
    
    return answer;
}