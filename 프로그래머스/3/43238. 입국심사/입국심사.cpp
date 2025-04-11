#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long max_t = (*max_element(times.begin(), times.end())) * (long long)n;
    long long min_t = 0;
    
    while(max_t > min_t + 1)
    {
        long long mid_t = (max_t + min_t) / 2;
        
        long long p = 0;
        for(int i = 0; i<times.size(); i++)
        {
            p += (mid_t / times[i]);
        }
        
        if(p >= n)
        {
            max_t = mid_t;
        }else{
            min_t = mid_t;
        }
    }
    
    return max_t;
}