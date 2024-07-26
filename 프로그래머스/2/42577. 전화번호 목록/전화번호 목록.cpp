#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    
    for(int i = 0; i<phone_book.size();i++){
        phone_book[i].erase(remove(phone_book[i].begin(), phone_book[i].end(), ' '), phone_book[i].end());
    }
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i<phone_book.size()-1;i++){
        if(phone_book[i].size() <= phone_book[i+1].size()){
            if(!phone_book[i].compare(phone_book[i+1].substr(0, phone_book[i].size()))){
                return false;
            }
        }
        if(phone_book[i+1].size() <= phone_book[i].size()){
            if(!phone_book[i+1].compare(phone_book[i].substr(0, phone_book[i+1].size()))){
                return false;
            }
        }
    }
    
    
    
    return true;
}