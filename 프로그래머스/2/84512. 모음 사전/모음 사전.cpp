#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
int A0000 = 781;
int A000 = 156;
int A00 = 31;
int A0 = 6;
int A = 1;

unordered_map<int, int> nums = {{0, 781}, {1, 156}, {2, 31}, {3, 6}, {4, 1}};
vector<int> numss = {781, 156, 31, 6, 1};
unordered_map<char,int> texts = {{'A', 0}, {'E', 1}, {'I', 2},{'O', 3}, {'U', 4}};

int solution(string word) {
    int answer = 0;
    
    for(int i = 0; i<5; i++){
        if(i == word.size()){
            break;
        }
        int nowin = texts[word[i]];
        answer += ((numss[i] * nowin) + 1);
        //cout << numss[nowin] << ", "<<i<<endl;
        
    }
    
    
    return answer;
}