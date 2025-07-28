#include <string>
#include <vector>

using namespace std;

int gdc(int a, int b){
    int mod = a % b;
    if(mod == 0) return b;
    
    return gdc(b, mod);
}

int solution(vector<int> arr) {
    int answer = 0;
    
    // [0] [1] 사이의 최소공배수
    answer = arr[0] * arr[1];
    if(arr[1] < arr[0]) answer /= gdc(arr[0], arr[1]);
    else     answer /= gdc(arr[1], arr[0]);
    
    // answer,  [i] 사이의 최소공배수
    for(int i = 2; i<arr.size(); i++){
        int tmp = arr[i] * answer;
        if(answer < arr[i]) tmp /= gdc(arr[i], answer);
        else     tmp /= gdc(answer, arr[i]);
        
        answer = tmp;
        
    }
    
    
    return answer;
}