#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){

    while(true){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0){
            break;
        }

        // a > b > c 순서로 정렬
        if(a < b)   swap(&a, &b);
        if(a < c)   swap(&a, &c);
        if(b < c)   swap(&b, &c);
        

        // 삼각형인지 확인
        if((b + c) <= a){
            cout << "Invalid\n";
            continue;
        }

        // Equilateral 
        if((a == b) && (b == c)){
            cout << "Equilateral\n";
            continue;
        }

        // Isosceles 
        if((a == b) || (b == c)){
            cout << "Isosceles\n";
            continue;
        }

        cout << "Scalene\n";

    }

    return 0;
}