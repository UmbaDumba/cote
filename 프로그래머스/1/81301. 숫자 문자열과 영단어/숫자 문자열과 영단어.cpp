#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;



int solution(string s) {
    int answer = 0;

    map<string, int> numbers = {{"zero" , 0}, {"one" , 1}, {"two" , 2}, {"three" , 3} ,{"four" , 4}, {"five" , 5}, {"six" , 6}, {"seven" , 7}, {"eight" , 8}, {"nine" , 9}};
        
    
    string str;
    string temp;
    for(int i = 0; i<s.size(); i++){
        if(isdigit(s[i])){
            str.push_back(s[i]);
            continue;
        }
        temp.push_back(s[i]);
        if ( numbers.find(temp) == numbers.end() ) {
        } else {
            // find
            int tnum = numbers[temp];
            char tchar = '0' + tnum;
            str.push_back(tchar);
            temp.clear();
        }
    }
    
    answer = stoi(str);
    
    return answer;
}