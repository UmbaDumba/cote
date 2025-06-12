#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int i = 0;
    int j = 0;
    int sum = 0;
    
    while(true)
    {
        if(j > n){
            break;    
        }
        
        if(sum < n){
            j++;
            sum += j;
        }else if(sum > n){
            i++;
            sum -= i;
        }else{
            //cout << i << ", "<<j<<endl;
            answer++;
            j++;
            i++;
            sum +=j;
            sum -=i;
        }
    }
    
    return answer;
}