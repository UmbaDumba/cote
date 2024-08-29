#include <string>
#include <vector>
#include <iostream>

using namespace std;



vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int size = n;
    
    for(int i = 0; i<size; i++){
        int num = s / n;
        if(num == 0){
            break;
        }
        answer.push_back(num);
        s -= num;
        n--;
    }
    
    if(answer.empty()){
        answer.push_back(-1);
    }
    
    
    
    
    return answer;
}