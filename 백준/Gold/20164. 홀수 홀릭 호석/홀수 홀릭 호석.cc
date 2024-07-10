#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

vector<int> split(int number){
    // {max, min} 형태로 리턴해주기
    int size = log10(number) + 1;
    if(size == 1){
        // 종료
        //cout << "size == 1 : "<<number<<", ";
        if((number%2) == 0){
            // 짝수
            //cout << "{0,0}"<<endl;
            return {0,0};
        }else{
            // 홀수
            //cout << "{1,1}"<<endl;
            return {1,1};
        }
        
    }else if(size == 2){
        // 두개로 나누기
        //cout << "size == 2 : "<<number<<", ";
        int odds = 0;
        int a = number/10;
        if((a%2) != 0){
            odds++;
        }
        int b = number%10;
        if((b%2) != 0){
            odds++;
        }
        int next = a + b;
        //cout << "a : "<<a<<", b : "<<b<<endl;
        odds += split(next)[0]; // 무조건 2자리숫자여서 [0], [1] 이 같음
        return {odds, odds};
    }

    //cout << "size == 3 : "<<number<<endl;

    int odds = 0;
    int iternum = number;
    vector<int> numbers;
    for(int i = size-1; i>=0; i--){
        int temp = iternum/pow(10,i);
        if((temp%2) != 0){
            odds++;
        }
        numbers.push_back(temp);
        iternum -= temp * pow(10, i);
    }

    // 3개로 나누기
    // -> 여러가지 경우가 있음
    // 숫자를 [size번째 자릿수], [size-1 번째], .... , [1번째] 모양으로 보면
    int max = 0;
    int min = 11;
    for(int i = size; i>=3; i--){
        // 첫번째 숫자가 끝나는 지점
        // [1자릿수] ~ [i번째 자릿수]
        for(int j = i-1; j>=2; j--){
            // 두번째 숫자가 끝나는 지점
            // [i-1번째 자릿수] ~ [j번째 자릿수]
            
            // 세번째 숫자는 자동으로 결정
            // [j-1번째 자릿수] ~ [1 번째 자릿수]

            int num1 = number / pow(10, i-1);
            int temp = number-(num1*(pow(10, i-1)));
            int num2 = temp / pow(10, j-1);
            int num3 = temp - (num2 * (pow(10, j-1)));

            vector<int> next = split(num1 + num2 + num3);
            if(next[0] > max){
                max = next[0];
            }
            if(next[1] < min){
                min = next[1];
            }
        }
    }
    return {max + odds, min + odds};
}


int main(){

    int n;
    cin >> n;

    vector<int> answer = split(n);

    cout << answer[1] << " "<<answer[0]<<endl;


    return 0;
}