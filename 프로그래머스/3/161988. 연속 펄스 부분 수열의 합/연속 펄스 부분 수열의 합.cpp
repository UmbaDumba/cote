#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    vector<long long> dp_minus(sequence.size(), 0);
    vector<long long> dp_plus(sequence.size(), 0);
    
    dp_plus[0] = sequence[0];
    dp_minus[0] = -sequence[0];
    
    // dp_plus : 홀수index에 마이너스
    // dp_minus : 짝수 index에 마이너스
    for(int i = 1; i<sequence.size(); i++)
    {
        if(i % 2 == 0)
        {
            dp_plus[i] = sequence[i] > dp_plus[i-1] + sequence[i] ? sequence[i] : dp_plus[i-1] + sequence[i];
            dp_minus[i] = -sequence[i] > dp_minus[i-1] - sequence[i] ? -sequence[i] : dp_minus[i-1] - sequence[i];
        }else{
            dp_plus[i] = -sequence[i] > dp_plus[i-1] - sequence[i] ? -sequence[i] : dp_plus[i-1] - sequence[i];
            dp_minus[i] = sequence[i] > dp_minus[i-1] + sequence[i] ? sequence[i] : dp_minus[i-1] + sequence[i];
        }
    }
    
    long long plus_max = *max_element(dp_plus.begin(), dp_plus.end());
    long long minus_max = *max_element(dp_minus.begin(), dp_minus.end());
    
    return plus_max > minus_max ? plus_max : minus_max;
}