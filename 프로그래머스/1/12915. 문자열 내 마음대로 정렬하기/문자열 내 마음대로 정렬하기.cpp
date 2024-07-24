#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int forn;

bool comp(string a, string b){
    if(a[forn] < b[forn]){
        return true;
    }else if(a[forn] == b[forn]){
        return a < b;
    }
    return false;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    forn = n;
    
    sort(answer.begin(), answer.end(), comp);
    
    
    return answer;
}