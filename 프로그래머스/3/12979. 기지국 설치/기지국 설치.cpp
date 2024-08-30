#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    float cover = (w * 2) + 1;
    int pre = stations[0];
    
    answer += (int)ceil((float)(stations[0] - 1 - w) / cover);
    
    
    for(int i = 1; i<stations.size(); i++){
        answer += (int)ceil((float)(stations[i] - pre - 1 - (2*w))/cover);
        pre = stations[i];
    }
    
    answer += (int)ceil((float)( n - stations[stations.size()-1]- w) / cover);
    


    return answer;
}