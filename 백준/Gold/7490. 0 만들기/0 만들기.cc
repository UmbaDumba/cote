#include <iostream>
#include <vector>
using namespace std;

int k;
string res;

void answer(int n){
    if(n > k){
        // 수식 계산
        char oper = '+';
        string nums = "";
        int sums = 0;
        for(int i = 0; i<res.size(); i++){
            if(isdigit(res[i])){
                nums.push_back(res[i]);
            }else{
                if(res[i] == ' ') continue;
                
                int num = stoi(nums);
                if(oper == '+') sums+=num;
                else if(oper == '-') sums-=num;
                

                nums="";
                oper = res[i];
            }
        }
        int num = stoi(nums);
        if(oper == '+') sums+=num;
        else            sums-=num;

        if(sums == 0){
            cout << res << "\n";
        }
        
        
        return;
    }

    // 숫자 연결
    res.push_back(' ');
    res.push_back(n+'0');
    answer(n+1);
    res.pop_back();
    res.pop_back();

    // +
    res.push_back('+');
    res.push_back(n+'0');
    answer(n+1);
    res.pop_back();
    res.pop_back();

    // -
    res.push_back('-');
    res.push_back(n+'0');
    answer(n+1);
    res.pop_back();
    res.pop_back();


}

int main(){

    int n;

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> k;
        res = "1";
        answer(2);

        cout << "\n";
    }

    return 0;
}