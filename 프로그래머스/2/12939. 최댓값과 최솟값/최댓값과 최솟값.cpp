#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    istringstream ss(s);
    string buffer;
    
    int max;
    int min;
    
    bool flag = true;
    
    while(getline(ss,buffer,' ')){
        int num = stoi(buffer);
        if(flag){
            max = num;
            min = num;
            flag = false;
        }
        if(max < num){
            max = num;
        }
        if(min > num){
            min = num;
        }
        
    }
    
    answer = to_string(min) + " " + to_string(max);
    
    return answer;
}