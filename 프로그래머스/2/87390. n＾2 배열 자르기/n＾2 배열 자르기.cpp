#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    
    /*
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int max;
            if(i > j){
                max = i;
            }else{
                max = j;
            }
            n2array[i][j] = max+1;
        }
    }
    */
    
    for(long long i = left; i<=right; i++){
        long long a = i/n;
        long long b = i%n;
        long long maxnum = a > b ? a : b;
        answer.push_back(maxnum+1);
    }
    
    return answer;
}