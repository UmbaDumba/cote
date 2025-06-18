#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, t;

bool is_ok(string str){
    if(s == str){
        return true;
    }
    if(str.size() <= s.size()){
        return false;
    }
    if(str[str.size()-1] == 'A'){
        string str2 = str;
        str2.pop_back();
        if(is_ok(str2)){
            return true;
        }
    }
    if(str[0] == 'B'){
        reverse(str.begin(), str.end());
        str.pop_back();
        return is_ok(str);
    }
    return false;
}

int main(){

    
    cin >> s >> t;

    if(is_ok(t)){
        cout << "1";
    }else{
        cout << "0";
    }
    

    return 0;
}