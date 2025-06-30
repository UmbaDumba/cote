#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    string str;
    cin >> str;

    long long num = 0;
    int i = 0; // str index

    while(i < str.size()){
        num++;
        string strnum = to_string(num);

        for(int j = 0; j<strnum.size(); j++){
            if(str[i] == strnum[j]){
                i++;
            }
        }
    }

    cout << num;

    return 0;
}